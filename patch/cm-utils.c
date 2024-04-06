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
            // Replace '/' with '_' in the repository name for directory path
            char repo_name[100]; // Adjust size according to your needs
            strcpy(repo_name, argv[2]); // Copy the repository name
            for (int i = 0; repo_name[i] != '\0'; i++) {
                if (repo_name[i] == '/') {
                    repo_name[i] = '_'; // Replace '/' with '_'
                }
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
