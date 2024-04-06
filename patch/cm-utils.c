#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "update") == 0) {
            printf("Executing update command...\n");
            system("yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git ~/hello && bash ~/hello/setup.sh");
            printf("System was updated...");

            DIR *dir;
            struct dirent *entry;

            // Open the ~/apps directory
            dir = opendir("~/apps");
            if (!dir) {
                perror("Error opening directory");
                return 1;
            }

            // Print all files and directories inside ~/apps
            printf("Files and directories inside ~/apps:\n");
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }

            // Close the directory
            closedir(dir);
            
            /*
            if (dir) {
                struct dirent *entry;
                int found = 0;
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, argv[2]) == 0) {
                        found = 1;
                        break;
                    }
                }
                closedir(dir);
                if (found) {
                    printf("Directory '%s' found in ~/apps/\n", argv[2]);
                    // Execute the script if found
                    char command[1000];
                    sprintf(command, "bash ~/apps/%s/cr.sh", argv[2]);
                    printf("Executing command: %s\n", command);
                    system(command);
                } else {
                    printf("Directory '%s' not found in ~/apps/\n", argv[2]);
                }
            } else {
                printf("Error opening ~/apps/ directory\n");
            }
            */
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
              
        else if (strcmp(argv[1], "run") == 0) {
            printf("Searching for '%s' in ~/apps/...\n", argv[2]);
            // Search for argv[2] in ~/apps/
            DIR *dir = opendir("~/apps/");
            if (dir) {
                struct dirent *entry;
                int found = 0;
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, argv[2]) == 0) {
                        found = 1;
                        break;
                    }
                }
                closedir(dir);
                if (found) {
                    printf("Directory '%s' found in ~/apps/\n", argv[2]);
                    // Execute the script if found
                    char command[1000];
                    sprintf(command, "bash ~/apps/%s/cr.sh", argv[2]);
                    printf("Executing command: %s\n", command);
                    system(command);
                } else {
                    printf("Directory '%s' not found in ~/apps/\n", argv[2]);
                }
            } else {
                printf("Error opening ~/apps/ directory\n");
            }
        }

        else {
            printf("Invalid argument\n");
        }
    } 
    else {        
        printf("No argument provided\n");
    }
    
    return 0;
}
