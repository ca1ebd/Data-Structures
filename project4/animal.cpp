/*
	animal.cpp

	author: 
	date:   

	Animal/20 questions program for CSCI 262, Fall 2018. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};

void read_preorder(node* tree, ifstream &fin) {
    string type_str = "";

    fin >> type_str;
    fin.ignore();
    getline(fin, tree->data);

    if(type_str == "#A"){
        return;
    }
    else if(type_str == "#Q"){
        node* child_left = new node;
        node* child_right = new node;

        tree->left = child_left;
        tree->right = child_right;

        read_preorder(tree->left, fin);
        read_preorder(tree->right, fin);
    }
    else{
        cout << "We're fucked";

    }
}

void write_preorder(node* root, ofstream &fout) {
    if((root->left == nullptr) and (root->right == nullptr)) { //leaf node
        fout << "#A " << root->data << endl;
        return;
    }
    else{
        fout << "#Q " << root->data << endl;
        write_preorder(root->left, fout);
        write_preorder(root->right, fout);
    }
}

node* read_game_tree() {
//    string infile = "animal.txt";
    string infile = "";
    cout << "Which file u wanna load: ";
    cin >> infile;
    cin.ignore();
    ifstream fin(infile);
    node* root_node = new node;

    read_preorder(root_node, fin);

    fin.close();

	return root_node;
}



bool get_yes_no() {
    string answer = "";
    cin >> answer;
    cin.ignore();
    return ((answer == "Y") or (answer == "y"));
}

void expand_game_tree(node* root, queue<bool> answers){
    node* current = root;
    node* leaf = nullptr;
    string new_animal = "";
    string new_prev = "";

    //show user game summary
    cout << "I asked the following: " << endl;
    bool current_answer = false;
//    while(!((current->left == nullptr) and (current->right == nullptr))) { //while not a leaf
    while(current != nullptr) { //while not a leaf
        current_answer = answers.front();
        answers.pop();
        if((current->left == nullptr) and (current->right == nullptr)){
            leaf = current;
        }
        if (current_answer){ //user answered yes
            cout << current->data << " YES" << endl;
            current = current->left;
        }
        else {
            cout << current->data << " NO" << endl;
            current = current->right;
        }
    }

    //prompt for new answers
    cout << "Enter a new animal in the form of a question," << endl << "e.g., 'Is it a whale?': ";
    //cin.ignore();
    getline(cin, new_animal);

    cout << "Now enter a question for which the answer is 'yes' for your new " << endl << "animal, and which does not contradict your previous answers: ";
//    cin.ignore();
    getline(cin, new_prev);

    //modify tree to include answers
    if(leaf == nullptr) {
        cout << "We're fucked" << endl;
        return;
    }
    string temp_current = leaf->data;
    leaf->data = new_prev;

    node* new_left = new node;
    new_left->data = new_animal;

    node* new_right = new node;
    new_right->data = temp_current;

    leaf->left = new_left;
    leaf->right = new_right;


}


void play_game(node* root){
    node* current = root;
    bool is_playing = true;
    bool is_leaf = false;
    bool answer = false;
    queue<bool> answers;

    while(is_playing){
        is_leaf = ((current->left == nullptr) and (current->right == nullptr));
        cout << current->data << " (Y/n)";
        answer = get_yes_no();
        answers.push(answer); //store answer in queue
        if(answer){ //user said yes
            if(is_leaf){
                cout << "Computer Wins!" << endl;
                is_playing = false;
            }
            else {
                current = current->left;
            }
        }
        else{
            if(is_leaf){
                cout << "Player Wins!" << endl;
                cout << "Would you like to expand the game tree? (Y/n): ";
                if(get_yes_no()){
                    expand_game_tree(root, answers);
                }
                is_playing = false;
            }
            else{
                current = current->right;
            }
        }
    }
}



void delete_game_tree(node* root){
	1==1;
}

void save_game_tree(node* root){
    string filename;
	cout << "Please enter the filename to save to: ";
	cin >> filename;
	cin.ignore();
	ofstream fout(filename);

	write_preorder(root, fout);

	fout.close();

}

int main() {
	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true) {
		string tmp;
		int choice;
		
		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());

		switch (choice) {
		case 1:
			play_game(root);
			break;
		case 2:
			save_game_tree(root);
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}
	
	delete_game_tree(root);
	return 0;
}



