/*
 * solution2.cpp
 *
 * Starter code for solving Problem 2: Mode
 * Lab 4 - Sorting
 * CSCI 262 Data Structures
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec;

    ifstream fin("numbers.txt");
    if (!fin) {
        cerr << "File 'numbers.txt' not found. Exiting." << endl;
        return -1;
    }

    for (int i = 0; i < 50000; i++) {
        int number;
        fin >> number;

        if (!fin) {
            cerr << "Error reading number from 'numbers.txt'.  Exiting." << endl;
            return -1;
        }

        vec.push_back(number);
    }
    fin.close();


    sort(vec.begin(), vec.end());

    int max_mode_index = -1;
    int max_mode_count = -1;

    for(int i=0; i<vec.size(); i++){



        int m = i;
        int count = 0;
        while(vec[m] == vec[m+1]){
            count++;
            m++;
            if(count > max_mode_count){
                max_mode_count = count;
                max_mode_index = i;
            }
        }
    }

    cout << "Mode Count: " << max_mode_count << endl;
    cout << "Mode Val: " << vec[max_mode_index] << endl;

    // print the mode of the values in numbers.txt

    return 0;
}