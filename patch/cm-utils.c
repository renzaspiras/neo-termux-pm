#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "update") == 0) {
            printf("Executing update command...\n");
            system("yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git ~/hello && bash ~/hello/setup.sh");
            printf("System was updated...");
        }

        else if (strcmp(argv[1], "add") == 0) {
            // Extract repository name from the input
            char *repo_name = strrchr(argv[2], '/'); // Find last occurrence of '/'
            if (repo_name == NULL) {
                // If '/' not found, use the entire argument as the repo name
                repo_name = argv[2];
            } else {
                // If '/' found, move to the character after '/'
                repo_name++;
            }

            // Construct the command string
            char command[1000]; // Adjust size according to your needs
            sprintf(command, "git clone https://github.com/%s ~/apps/%s", argv[2], repo_name);
            // Execute the command
            printf("Executing command: %s\n", command);
            system(command);
        }

        else {
            printf("Invalid argument\n");
        }
    } else {
        printf("No argument provided\n");
    }
    
    return 0;
}
