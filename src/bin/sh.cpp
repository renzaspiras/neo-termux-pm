/*
  Why Too Many Comments?
  I include too many comments on almost each line because:
    - At this point, I can code this language, and after a year, I cannot.
    - I have short term memory.
    - And it is better practice for me, to improve, and so that I can debug it easier on the future even JUST IN CASE I FORGOT TO CODE IN C++
    - Also, most of the codes are not 100% created by me since I based from the internet reference such as reddit, stackoverflow, and etc.
*/

// Standard Input Output Library
#include <iostream>    

// Standard Input Output Library
#include <stdio.h>     

// String handling Library
#include <string>      

// POSIX operating system API
#include <unistd.h>    

// System call wait functions
#include <sys/wait.h> 

// Terminal I/O control
#include <termio.h>    


// The following line allows you to use symbols from the std namespace
// without explicitly specifying the namespace prefix std::
// It simplifies code by eliminating the need for repetitive namespace prefixes.
/*
  @Example:
  From
  std::cout << "Hello World";

  To
  cout << "Hello World";
*/
using namespace std;

/*
  This function modifies the terminal settings to enable non-canonical mode, 
  where input is processed character-by-character instead of line-by-line, 
  and characters are not echoed back to the terminal.
*/
void setNonCanonicalMode() {
    struct termios t;  // Declare a termios structure variable
    tcgetattr(STDIN_FILENO, &t);  // Get current terminal attributes
    t.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Apply modified attributes to terminal
}

// Function to reset terminal to canonical mode
void resetCanonicalMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

string handleInput(){
  string input;
  char c;

  while (true){
    c = getchar();
    if(c ==  '\n'){
      break;
    }

    else if(c == '\x1b'){
      char c2 = getchar();
      char c3 = getchar();

      if (c2 == '[' && c3 == 'A'){
        //up
      }
      else if(c2 == '[' && c3 == 'B'){
        //down
      }
    }

    else if(c == 127){ // Backspace
      if(!input.empty()){
        cout << "\b \b";
        input.pop_back();
      }
    }

    else if(c == '\t'){
      cout << '\t';
      input.push_back('\t');
    }

    else{
      input.push_back(c);
      cout << c;
    }
  }

  return input;
}


int main(){
  // Calling the set cannonical mode......
  setNonCanonicalMode();
  while (true){
    cout << "> ";
    string input;

    input = handleInput();

    if (input == "exit"){
      break;
    }

    else if(input == "clear"){
      cout << "\033[2J\033[H";
    }

    else{
      cout << "ok\n";
    }

    pid_t pid = fork();
    if(pid == 0){
      execlp(input.c_str(), NULL);
      cout << "\n";
      exit(EXIT_FAILURE);
    }
    else if(pid > 0){
      int status;
      cout << "\n";
      waitpid(pid, &status, 0);
      cout << "\n";
    }
    else{
      cerr << "Error Forking Process\n";
    }
  }

  resetCanonicalMode();
  return 0;
}