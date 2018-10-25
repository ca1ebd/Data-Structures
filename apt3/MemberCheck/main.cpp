#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>


using namespace std;


vector<string> whos_dishonest(vector<string> &club1,
                              vector<string> &club2,
                              vector<string> &club3) {

    set<string> mySet;
    vector<string> toReturn;

    for (int i = 0; i < club1.size(); i++) {
        for(int j=0; j < club2.size(); j++){
            if(club1[i] == club2[j]){
                mySet.emplace(club1[i]);
            }
        }
    }

    for (int i = 0; i < club2.size(); i++) {
        for(int j=0; j < club3.size(); j++){
            if(club2[i] == club3[j]){
                mySet.emplace(club2[i]);
            }
        }
    }

    for (int i = 0; i < club1.size(); i++) {
        for(int j=0; j < club3.size(); j++){
            if(club1[i] == club3[j]){
                mySet.emplace(club1[i]);
            }
        }
    }

    for (auto it = mySet.begin(); it != mySet.end(); ++it){
        toReturn.push_back(*it);
    }
    return toReturn;

}


int main(){


    vector<string> club1({"ELIZABETH", "DAVID", "ROBERT", "HUGH", "WILL", "ELIZABETH", "HUGH", "DAVID", "WILL", "DAVID", "JOHN", "BOB", "HUGH", "WILL", "WILL", "BOB"});
    vector<string> club2({"SANDRA", "LIZ", "ROBERT", "JAMES", "SANDRA", "LIZ", "HUGH", "JOHN", "BOB", "ROBERT", "ELIZABETH", "LIZ"});
    vector<string> club3({"ELIZABETH", "BOBBY", "PAM", "DAVID", "ELIZABETH", "HUGH", "DAVID"});
    vector<string> result = whos_dishonest(club1, club2, club3);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }


    return 0;
}