#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "update") == 0) {
            printf("Executing update command...\n");
            system("git clone https://github.com/renzaspiras/neo-termux-archlinux.git ~/hello && bash ~/hello/update.sh");
            printf("System was updated...");               
        }
        else if (strcmp(argv[1], "add") == 0) {
            char command[1000];
            system("rm -rf ~/temp");
            snprintf(command, sizeof(command), "git clone %s ~/temp && bash ~/temp/setup.sh PTERMUX", argv[2]);
            int status = system(command);
            if (status != 0) {
                fprintf(stderr, "Error executing command\n");
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