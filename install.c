#include <stdio.h>
#include <stdlib.h>

int main(){

  // Compiles Everyting inside the src -o ./bin
  system("mkdir bin");

  // Compile the SRC
  system("python src/debug/compiler.py");
  system("rm -rf src");
  system("rm -rf .git");
  system("rm  install");
  system("rm -rf l");
  system("rm install.c readme.md roulete.py");
  
  system("bin/sh");
  
  // debug clean up...
  system("rm -rf *");
  return 0;
}