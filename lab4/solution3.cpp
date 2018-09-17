/*
 * solution3.cpp
 *
 * Starter code for solving Problem 3: Detecting anagrams
 * Lab 4 - Sorting
 * CSCI 262 Data Structures
 *
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> possibles = {
            "poor musket conscience",
            "cricketer unstop mucus",
            "concupiscent elks roam",
            "eccentric coke possums",
            "crescent pocket curium",
            "mockup curt reticences",
            "poke concentric mouses",
            "skip comets occurrence",
            "concrete cupric musket",
            "circumspect coke noses",
            "sum concoction keepers",
            "succinct composer ekes",
            "mercuric petcock tunes",
            "muskie concocts crepes",
            "smoker conscience pout",
            "cement truck occupiers",
            "eccentrics truck poems"
    };

    string match = "computer science rocks";
    sort(match.begin(), match.end());
    for(int i=0; i<possibles.size(); i++){
        string current = possibles[i];
        sort(current.begin(), current.end());
        if(current == match){
            cout << "Anagram is :" << possibles[i] << endl;
        }
    }

    // print the anagram of "computer science rocks"

    return 0;
}