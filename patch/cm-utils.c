#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "update") == 0) {
            system("python ~/bin/apps.py");
            printf("Executing update command...\n");
            system("yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git ~/hello && bash ~/hello/setup.sh");
            printf("System was updated...");               
        }
        else if (strcmp(argv[1], "add") == 0) {
            char command[1000];
            snprintf(command, sizeof(command), "git clone %s ~/temp && bash ~/temp/setup.sh TERMUX", argv[2]);
            int status = system(command);
            if (status != 0) {
                fprintf(stderr, "Error executing command\n");
                return 1;
            }
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
            
            // Search for argv[2] in ~/apps/
            DIR *dir = opendir(path);
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
                    snprintf(command, sizeof(command), "bash %s/%s/cr.sh", path, argv[2]);
                    printf("Executing command: %s\n", command);
                    system(command);
                } else {
                    printf("Directory '%s' not found in ~/apps/\n", argv[2]);
                }
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
