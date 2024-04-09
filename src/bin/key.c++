#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <termios.h>
#include <stdio.h>

using namespace std;

// Function to set terminal to non-canonical mode
void setNonCanonicalMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Function to reset terminal to canonical mode
void resetCanonicalMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Function to handle input while typing
string handleInput() {
    string input;
    char c;

    // Read each character while typing
    while (true) {
        c = getchar();
        if (c == '\n') {
            break;
        } 
        else if (c == '\x1b') { // Check for escape character (indicating possible arrow key)
            // Read the next two characters to determine if it's the up arrow key
            char c2 = getchar();
            char c3 = getchar();
            if (c2 == '[' && c3 == 'A') { // Up arrow key
                //cout << "Up arrow key pressed" << endl;
                cout << "u";
                cout << "p";
                input.push_back('u');
                input.push_back('p');
                //input = "banana"; // Replace input with "banana"
                //break;
            }
            else if (c2 == '[' && c3 == 'B') { // Up arrow key
                //cout << "Up arrow key pressed" << endl;
                cout << "d";
                cout << "n";
                input.push_back('n');
                input.push_back('n');
                //input = "banana"; // Replace input with "banana"
                //break;
            }            
        } 
        
        else if (c == 127) { // Check for backspace key
            if (!input.empty()) {
                cout << "\b \b"; // Erase character from screen
                input.pop_back(); // Remove last character from input
            }
        } 
        else if (c == '\t') { // Check for Tab key
            cout << "t";
            input.push_back('t');
        }
        else {
            input.push_back(c);
            cout << c; // Echo character to screen
        }
    }

    return input;
}

int main() {
    setNonCanonicalMode();
    
    while (true) {
        cout << "> ";
        
        string input = handleInput();
        
        if (input == "exit")
            break;

        //cout << "Input: " << input << endl;

        // Fork a new process
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execlp(input.c_str(), input.c_str(), NULL);
            //cerr << "Error executing command\n";
            cout << "\n\n";
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Parent process
            int status;
            cout << "\n";
            waitpid(pid, &status, 0); // Wait for the child process to finish
            cout << "\n";
        } else {
            // Error forking
            cerr << "Error forking process\n";
        }
    }
    
    resetCanonicalMode();
    
    return 0;
}
