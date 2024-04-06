#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h> // Include this for access()

void execute_up_sh(const char *filename);

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
              
        else if (strcmp(argv[1], "run") == 0) {
            printf("Searching for '%s' in ~/apps/...\n", argv[2]);
            // Get the value of the HOME environment variable
            char *home = getenv("HOME");
            if (home == NULL) {
                printf("HOME environment variable is not set.\n");
                return 1;
            }
            // Concatenate the path properly
            char path[1000];
            snprintf(path, sizeof(path), "%s/apps/", home);
            
            // Open the directory
            DIR *dir = opendir(path);
            if (dir) {
                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                    // Skip if entry is not a directory or if it's . or ..
                    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                        continue;

                    // Construct the full path of the entry
                    char entry_path[1000];
                    snprintf(entry_path, sizeof(entry_path), "%s%s%s", path, entry->d_name, "/up.sh");

                    // Check if the entry is a directory
                    struct stat statbuf;
                    if (stat(entry_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
                        // Execute up.sh for each directory
                        execute_up_sh(entry_path);
                    }
                }
                closedir(dir);
            } else {
                printf("Error opening ~/apps/ directory\n");
                return 1;
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

void execute_up_sh(const char *filename) {
    // Check if file exists
    if (access(filename, F_OK) == -1) {
        fprintf(stderr, "File not found: %s\n", filename);
        return;
    }

    // Check if file is executable
    if (access(filename, X_OK) == -1) {
        fprintf(stderr, "File is not executable: %s\n", filename);
        return;
    }

    // Execute the file
    if (system(filename) == -1) {
        perror("system");
        exit(EXIT_FAILURE);
    }
}
