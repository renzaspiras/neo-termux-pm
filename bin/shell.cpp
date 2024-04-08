#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main(){
  while (true)
  {
    /* code */
    string input;

    cout << "┌──(Testing)\n└─$ ";
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
      string debug = "./bin";
      string neo = "~/neo/bin";
      
      fs::path directory_path = debug; // Current directory
      for (const auto& entry : fs::directory_iterator(directory_path)) {
        // Check if it's a directory
        if (entry.is_directory()) {
            cout << entry.path().filename() << endl;
        }
      }
    }    
  }
  
  return 0;
}