/*
 * solution1.cpp
 *
 * Starter code for solving Problem 1: Selection & Median
 * Lab 4 - Sorting
 * CSCI 262 Data Structures
 *
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> vec;

    ifstream fin("words.txt");
    if (!fin) {
        cerr << "File 'words.txt' not found. Exiting." << endl;
        return -1;
    }

    for (int i = 0; i < 50000; i++) {
        string word;
        fin >> word;

        if (!fin) {
            cerr << "Error reading words from 'words.txt'.  Exiting." << endl;
            return -1;
        }

        vec.push_back(word);
    }
    fin.close();

    sort(vec.begin(), vec.end());

    // print 8489th, 38719th, and 2796th words from vec
    cout << "8489th Word: " << vec[8489-1] << endl;
    cout << "38719th Word: " << vec[38719-1] << endl;
    cout << "2796th Word: " << vec[2796-1] << endl;

    return 0;
}