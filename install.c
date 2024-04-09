#include <stdio.h>
#include <stdlib.h>

int main(){

  // Compiles Everyting inside the src -o ./bin
  system("mkdir bin");
  system("python src/debug/compiler.py");
  return 0;
}