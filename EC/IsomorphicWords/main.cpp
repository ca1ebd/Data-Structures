//
// Created by calebdudley on 12/10/2018.
//

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int count_pairs(vector<string> &words) {
    map<char, int> maps;
    string order_str = "";
    int unique_char_count = 0;
    vector<string> valued_strings;
    int match_count = 0;

    for(int i=0; i<words.size(); i++){
        unique_char_count = 0;
        maps.clear();
        order_str.clear();
        for(int j=0; j<words[i].length(); j++){
            if(!maps.count(words[i][j])){
                maps[words[i][j]] = (unique_char_count++);
            }
            order_str += to_string(maps[words[i][j]]);
        }
        valued_strings.push_back(order_str);
    }

    for(int i=0; i<valued_strings.size(); i++){
        for(int j=i+1; j<valued_strings.size(); j++){
            if(valued_strings[i] == valued_strings[j]){
                match_count++;
            }
        }
    }

    return match_count;

}

int main(){
    vector<string> words = {"aa", "ab", "bb", "cc", "cd"};
    cout << count_pairs(words) << endl;
    return 0;
};

