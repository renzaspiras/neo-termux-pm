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
            printf("git clone https://github/%s ~/apps/\n", argv[2]);
        }
        else {
            printf("Invalid argument\n");
        }
    } else {
        printf("No argument provided\n");
    }
    
    return 0;
}
