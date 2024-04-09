#include <stdio.h>
#include <stdlib.h>

int main(){

  // Compiles Everyting inside the src -o ./bin
  system("mkdir bin");

  // Compile the SRC
  system("python src/debug/compiler.py");
  system("rm -rf ./l");
  system("bin/sh");
  return 0;
}