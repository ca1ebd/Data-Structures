/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author:

    last modified: 9/24/2017
*/

#include <fstream>
#include <iostream>
#include "hangman.h"

using namespace std;

// constructor
hangman::hangman() { 
    //Read in and store words from dictionary.txt
    string infile = "dictionary.txt";
    ifstream fin(infile);
    string tempWord = "";
    while(!fin.eof()){
        fin >> tempWord;
        _full_dict[tempWord.length()].push_back(tempWord);
    }
    // TODO: Initialize game state variables

}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses, int word_length, bool see_words) {
    _guesses_remaining = num_guesses;
    _word_length = word_length;
    _see_words = see_words;

    //build family representation string
    for(int i=0; i < word_length; i++){
        _family_rep += '_';
    }
    _display_rep = _family_rep;

    _possible_words = _full_dict[_word_length];

}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    _families.clear();
    _guessed_chars += c;

    for(int i=0; i < _possible_words.size(); i++){
        for(int j=0; j < _possible_words[i].length(); j++) {
//            if(_possible_words[i][j] == c){
//                _family_rep[j] = c;
//            }
            if (_possible_words[i][j] != c) {
                _family_rep[j] = '_';
            } else {
                _family_rep[j] = c;
            }
        }
        _families[_family_rep].push_back(_possible_words[i]); //add each word to map under its family representation
    }

    //find the largest list
    int largest = _families[_families.begin()->first].size(); //set the largest value to size of the zeroth list in map
    auto largest_index = _families.begin();
    for(auto it = _families.begin(); it != _families.end(); ++it){
        if(_families[it -> first].size() > largest){
            largest_index = it;
            largest = _families[largest_index->first].size();
        }
    }

    _possible_words = largest_index->second; //"choose" a family
    string chosen_family_rep = largest_index->first;

    if (_see_words) {
        cout << "The word list has " << largest << " words" << endl;
        for(int i=0; i<_possible_words.size(); i++){
            cout << _possible_words[i];
            cout.flush();
            if(i%10 == 0){
                cout << endl;
            }
            else{
                cout << ", ";
                cout.flush();
            }
        }
    }

    //report back whether the guess was in the family
    bool guess_in_family = false;
    for(int i=0; i<chosen_family_rep.length(); i++){
        if(chosen_family_rep[i] == c){ //guess is in word
            guess_in_family = true;
            _display_rep[i] = c;
        }
    }
    if(!guess_in_family) { _guesses_remaining--; }

    return guess_in_family;

//    if(largest_index->first != _family_rep){ //did not select blank family
//        //update display rep with new family info
//        for(int i=0; i < _display_rep.length(); i++){
//            if(chosen_family_rep[i] != '_'){
//                _display_rep[i] = chosen_family_rep[i];
//            }
//        }
//
//        return true;
//    }

//    //guess was not in word
//    _guesses_remaining--;
//    return false;

}


// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return _display_rep;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return _guesses_remaining;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    return _guessed_chars;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    for(int i=0; i < _guessed_chars.length(); i++){
        if(_guessed_chars[i] == c){
            return true;
        }
    }
    return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    for(int i=0; i<_display_rep.length(); i++){
        if(_display_rep[i] == '_'){
            return false;
        }
    }
    return true;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    return _guesses_remaining == 0;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    return _possible_words[0];
}

bool hangman::isValidLength(int length) {
    if(_full_dict.count(length)){
        return true;
    }
    return false;
}

void hangman::clear(){
    _families.clear();
    _possible_words.clear();
    _family_rep = "";
    _display_rep = "";
    _guesses_remaining = 0;
    _word_length = 0;
    _see_words = false;
    _guessed_chars = "";
}


