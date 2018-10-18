/*
    lab07c.cpp

    Author: Clayton Kramp

    Created: 10/10/2018

*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

// TODO: Implement your encryption function!
inline int encrypt (string str) {
    int output = 0;
    for(int i=0; i<str.size(); i++){
        output+=int(str[i]);
    }
    return output%1000;
}

int main() {
    // open dictionary and read in all the words
    int encryptedKey;
    cout << "What is your encryption key?" << endl;
    cin >> encryptedKey;

    cout << "Reading dictionary...";
    ifstream fin("dictionary.txt");
    if (!fin) {
        cerr << "Could not open 'dictionary.txt' for reading, exiting." << endl;
        return -1;
    }
    // Our encryption map data structure   
    map<int, vector<string> > encryptionMap;
    string word;
    while (!fin.eof()) {
        getline(fin, word);
        // For each word, encrypt it!
        int encrypted = encrypt(word);
        // Add the encrypted word into our map
        encryptionMap[encrypted].push_back(word);
    }
    fin.close();
    cout << "done." << endl;
    
    // Given an encryption key, find the words that map to it
    cout << "Finding possible words for the encryption " << encryptedKey << endl;
    vector<string> vec = encryptionMap[encryptedKey];
    for (string i : vec) {
        cout << i << " ";
    }
    vector<string> myVec = encryptionMap[378];
    //cout << myVec[0];
    cout << endl;
    cout << encrypt("hello") << endl;
    cout << encrypt("trustworthy") << endl;
    cout << encrypt("airworthy") << endl;
    return 0;
}
