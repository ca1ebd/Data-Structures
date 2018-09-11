#include <sstream>
#include <iostream>

using namespace std;

int main() {
    cout << "Please enter a string: ";
    string inputString = "";
    getline(cin, inputString);

    istringstream ssin(inputString);

    while(!ssin.eof()){
        string tempString = "";
        ssin >> tempString;
        cout << tempString << endl;
    }


    return 0;
}