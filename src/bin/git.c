#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Concatenate all the arguments into a single string
    char command[1024] = "git";
    for (int i = 1; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }

    // Execute the command
    system(command);

    return 0;
}
