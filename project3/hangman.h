
#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: 

    last modified: 9/24/2017
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
    public:
        hangman();

        // start a new game where player gets num_guesses unsuccessful tries
        void start_new_game(int num_guesses, int word_length, bool see_words);

        // player guesses letter c; return whether or not char is in word
        bool process_guess(char c);

        // display current state of word - guessed characters or '-'
        string get_display_word();

        // How many guesses remain?
        int get_guesses_remaining();

        // What characters have already been guessed (for display)?
        string get_guessed_chars();

        // Has this character already been guessed?
        bool was_char_guessed(char c);

        // Has the game been won/lost?  (Else, it continues.)
        bool is_won();
        bool is_lost();

        // Return the true hidden word.
        string get_hidden_word();
        bool isValidLength(int length);
        void clear();

    private:
        map<int, vector<string>> _full_dict; //full dictionary from file
        map<string, vector<string>> _families;
        vector<string> _possible_words;
        string _family_rep = "";
        string _display_rep = "";
        int _guesses_remaining = 0;
        int _word_length = 0;
        bool _see_words = false;
        string _guessed_chars = "";

    
};

#endif
