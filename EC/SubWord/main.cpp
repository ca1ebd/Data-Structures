//
// Created by calebdudley on 12/10/2018.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int longest(string input, vector<string> &words) {
    bool possible = true;
    vector<string> possibilities;

    bool letter_matched = false;
    int position_input = 0;
    for(int i=0; i<words.size(); i++){ //for each word
        position_input = 0;
        possible = true;
        for(int j=0; j<words[i].length(); j++){ //for each letter in each word
            //if each letter cannot be found in the word, in order, possible is false
            letter_matched = false;
            while(possible and (!letter_matched)){
                if(words[i][j] == input[position_input]){
                    letter_matched = true;
                    position_input++;
                    //found letter in word, can check next letter of small word
                }
                else if(position_input >= input.length()-1) {
                    possible = false;
                }
                else{
                    //continue checking
                    position_input++;
                }
            }
        }

        if(possible){
            possibilities.push_back(words[i]);
        }
    }
    string largest = "";
    for(int i=0; i<possibilities.size(); i++){
//        cout << possibilities[i] << ", " << endl;
        if (possibilities[i].length() > largest.length()){
            largest = possibilities[i];
        }
    }

    return int(largest.length());
}

int main(){
    string input = "pluuifeti";
    vector<string> words = {"boyfriend", "icy", "items", "malfunctioning", "sanguinary", "adenoidal", "surefire", "scaffolding", "wilder", "wholesaler", "mingles", "atone", "rehearses", "firestorms", "grannie", "cap", "refiling", "climbs", "hypothetically", "facsimiles", "quasi", "lifetimes", "philharmonic", "tracer", "neutralizing", "ostriches", "looked", "reduced", "instruments", "gruelled", "miens", "uptakes", "floozie", "marketers", "meritocracies", "svelte", "monarchism"};

    cout << longest(input, words);
}


