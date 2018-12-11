//
// Created by calebdudley on 12/10/2018.
//

#include <iostream>
#include <map>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    map<string, int> var_map;
    queue<string> results;

    string command = "";
    //variables used for commands
    string number = "";
    string var_name = "";

    //variables used for evaluating
    string first_var = "";
    string second_var = "";
    string comparator = "";

    string result_str = "";
    bool result_bool = false;

    const string UNDEFINED = "undefined";
    const string TRUE = "true";
    const string FALSE = "false";

    istream *my_istr;
    my_istr = &cin;
    my_istr = new ifstream("my_program.txt");

//    while(command != "q"){
//    while(!cin.eof()){
    while (cin >> command) {
        //cin >> command;
        if (command == "define") {
            cin >> number;
            cin >> var_name;
            var_map[var_name] = stoi(number);
        }
        if (command == "eval") {
            cin >> first_var;
            cin >> comparator;
            cin >> second_var;

            if ((!var_map.count(first_var)) or (!var_map.count(second_var))) {
                result_str = UNDEFINED;
            } else {
                switch (comparator[0]) {
                    case '>':
                        result_bool = var_map[first_var] > var_map[second_var];
                        break;
                    case '<':
                        result_bool = var_map[first_var] < var_map[second_var];
                        break;
                    case '=':
                        result_bool = var_map[first_var] == var_map[second_var];
                        break;
                    default:
                        cout << "Yikes" << endl;
                        break;
                }
                if (result_bool) {
                    result_str = TRUE;
                } else {
                    result_str = FALSE;
                }
            }
            results.push(result_str);
        }
    }


    while (!results.empty()) {
        cout << results.front() << endl;
        results.pop();
    }

}


