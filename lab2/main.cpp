#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    ifstream fin;
    fin.open("haiku.txt");

    if(!fin) { //check to make sure file is found
        cerr << "can't find file" << endl;
    }

    ofstream fout;
    fout.open("haiku2.txt");

    if(!fout){
        cerr << "can't fine file" << endl;
    }

    while(!fin.eof()){
        string line = "";
        getline(fin, line);
        fout << line << endl;
    }

    fin.close();
    fout.close();

}