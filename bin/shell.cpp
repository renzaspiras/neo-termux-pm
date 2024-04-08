#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
#include <vector>
#include <cstdlib> // Include the header for system()

string getFirstWord(const string& str) {
    istringstream iss(str);
    string firstWord;
    iss >> firstWord;
    return firstWord;
}


int main(){
  while (true)
  {
    /* code */
    string input;

    cout << "\n┌──(Testing)\n└─$ ";
    getline(cin, input);

    if(input == "exit"){
      break;
    }

    else if (input.empty())
    {
      cout << "\n";
    }

    else if(input == "clear"){
      cout << "\033[2J\033[1;1H"; 
    }

    else{
      string debug = "./";
      string test = "./test/bin/";
      string neo = "~/neo/bin/";

      string directory_path = neo;
      if(!fs::exists(directory_path) || !fs::is_directory(directory_path)){
        cerr << "Error" << endl;
        return 1;
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
          const char* command = input.c_str();
          system(command);
          cout << "" << endl;
          break;          
        }
      }
      if(!found){
        cout << "Command not found" << endl;
      }
    }
  }
  
  return 0;
}