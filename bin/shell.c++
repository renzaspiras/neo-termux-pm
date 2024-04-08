#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
#include <vector>
#include <cstdlib> // Include the header for system()

// ANSI escape codes for colors
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"


//--> This version only works on termux
std::string getFirstWord(const std::string& str) {
    // Find the position of the first space character
    size_t pos = str.find_first_of(" \t");

    // Extract the substring from the beginning of the string up to the space
    if (pos != std::string::npos) {
        return str.substr(0, pos);
    } else {
        // If no space is found, return the entire string
        return str;
    }
}


int main(){
  while (true)
  {
    /* code */
    string input;

    std::cout << "\n" << GREEN << "┌──(root@archlinux)" << RESET << std::endl;
    std::cout << WHITE << "└─" << RESET << "$ ";
    getline(cin, input);

    if(input == "exit"){
      break;
    }

    else if (input.empty())
    {
      cout << "\n";
    }

    else if(input == "clear"){
      system("clear");
    }

    else{
      string debug = "./";
      string test = "./test/bin/";
      string neo = "/data/data/com.termux/files/home/neo/bin/";

      string directory_path = neo;
      if(!fs::exists(directory_path) || !fs::is_directory(directory_path)){
        cout << input + ": Command not found" << endl;
        continue;
      }
      vector<string> files;
      for (const auto& entry : fs::directory_iterator(directory_path)) {
        if (fs::is_regular_file(entry)) {
          files.push_back(entry.path().filename());
        }
      }
      bool found = false;
      for (const auto& file : files) {
        if(file == getFirstWord(input)){
          found = true;
          string full_command;
          if(input.find('/') != string::npos){
            full_command = input;
          }
          else {
            full_command = directory_path + "/" + input;
          }
          system(full_command.c_str());
          cout << "" << endl;
          break;
        }
      }
      if(!found){
        cout << input + ": Command not found" << endl;
      }
    }
  }
  
  return 0;
}