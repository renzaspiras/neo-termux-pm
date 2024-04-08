#include <iostream>

using namespace std;

int main(){
  while (true)
  {
    /* code */
    string input;

    cout << "┌──(Testing)\n└─$ ";
    cin >> input;

    if(input == "exit"){
      break;
    }

    //cout << input << endl << endl;
  }
  
  return 0;
}