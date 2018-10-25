#include <vector>
#include <string>
#include <map>
#include <iostream>


using namespace std;



string encrypt(string message){
    map<char, char> myMap;
    int used_count = 'a';
    for(int i=0; i<message.size(); i++){
        pair<map<char, char>::iterator, bool> myPair;
        myPair = myMap.insert(pair<char, char>(message[i], char(used_count)));
        if(myPair.second){
            used_count++;
        }
    }
    string toReturn = "";
    for(int i=0; i<message.length(); i++){
        toReturn += myMap[message[i]];
    }

    return toReturn;
}


int main(){

    cout << encrypt("hello");

    return 0;
}