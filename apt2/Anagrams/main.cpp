#include <vector>
#include <string>
#include <locale>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> anagrams(vector<string> phrases) {
    locale loc;

    vector<string> origVec = phrases;

    //sort vector, remove spaces, and make everything lowercase
    for(int i=0; i<phrases.size(); i++){
        for(int j=0; j<phrases[i].length(); j++){
            phrases[i][j] = tolower(phrases[i][j], loc);

        }
        phrases[i].erase(remove_if(phrases[i].begin(), phrases[i].end(), ::isspace), phrases[i].end());
        sort(phrases[i].begin(), phrases[i].end());
    }


    for(int i=0; i<phrases.size(); i++){
        for(int j=1; j<phrases.size(); j++){
            if(phrases[i] == phrases[j]){
                cout << "Match: " << origVec[i] << " = " << origVec[j] << endl;
            }
        }
    }



    for(int i=0; i<origVec.size(); i++){
        cout << origVec[i] << endl;
    }
    cout << endl;

    for(int i=0; i<phrases.size(); i++){
        cout << phrases[i] << endl;
    }
}

int main() {
    vector<string> testVec = {"Aaagmnrs", "TopCoder", "anagrams", "Drop Cote"};
    anagrams(testVec);
    return 0;
}