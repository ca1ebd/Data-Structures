/*
    main.cpp
    
    Main function and support functions for the image editor project.
    Supplies the user interface and drives the drawing_window object.

    author: C. Painter-Wakefield

    last modified: 8/31/2018
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <future>
#include <chrono>

#include "image_editor.h"
#include "drawing_window.h"

using namespace std;

void load_file(image_editor&);
void save_file(image_editor&);
void display_image(image_editor&, drawing_window&);
void user_interface(image_editor*, drawing_window*);
bool user_action(image_editor*);
void show_menu(image_editor&);
void trim(string&);

int main() {
    cout << "Welcome to Image Editor!" << endl;
    cout << "========================" << endl << endl;
    
    // create an editor object and initialize
    image_editor editor;
    load_file(editor);

    // create a drawing window
    drawing_window window("Image Editor");

    // display the initial image
    display_image(editor, window);

    // start drawing window, executing user interface in its own thread
    window.start(user_interface, &editor, &window);

    return 0;
}

void user_interface(image_editor* editor, drawing_window* window) {
    // loop until user calls it quits
    while (true) {
        // get user input asynchronously so we can quit immediately if
        // drawing window gets closed by user
        future<bool> fut = async(user_action, editor);
        while (fut.wait_for(chrono::milliseconds(10)) != future_status::ready) {
            if (window->is_stopped()) exit(0);
        }
        if(fut.get()) {
            display_image(*editor, *window);
        } else {
            window->stop();
            break;
        }
    }
}

// Obtain a filename from the user and attempt to open an input filestream
// on it; then ask the image editor to load from the filestream.
void load_file(image_editor& editor) {
    // loop until successful load
    while (true) { 
        string img_file_name;
        cout << "Please enter the image filename, e.g., \"blocks.ppm\": ";
        getline(cin, img_file_name);
        trim(img_file_name);
        ifstream data(img_file_name);
        if (!data) {
            cerr << "Error opening file \"" << img_file_name << "\"" << endl;
            continue;
        }
        if (editor.load(data)) {
            data.close();
            return;
        } else {
            data.close();
            cerr << "Input file '" << img_file_name;
            cerr << "' appears to not be a PPM!" << endl;
        }
    }
}

// Obtain a filename from the user and attempt to open an output filestream
// on it; then ask the image editor to save onto the filestream.
void save_file(image_editor& editor) {
    // get the filename to process first
    string img_file_name;
    cout << "Please enter a filename to save to, e.g., \"myimage.ppm\": ";
    getline(cin, img_file_name);
    trim(img_file_name);

    // open the file
    ofstream out(img_file_name);
    while (!out) {
        cerr << "Error opening file \"" << img_file_name << "\"" << endl;
        out.clear();
        cout << "Please enter a filename to save to, e.g., \"myimage.ppm\": ";
        getline(cin, img_file_name);
        trim(img_file_name);
        out.open(img_file_name);
    }

    editor.save(out);

    cout << "File saved." << endl;

    out.close();
}

// Display the current image data on the drawing window (opening it first,
// if necessary).
void display_image(image_editor& editor, drawing_window& window) {
    int rows = editor.get_rows();
    int columns = editor.get_columns();

    if (rows != window.get_height() || columns != window.get_width()) {
        window.resize(columns, rows);
    }

    int r, g, b;
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
            r = editor.get_red(y, x);
            g = editor.get_green(y, x);
            b = editor.get_blue(y, x);
            window.set_color(x, y, r, g, b);
        }
    }
}

// Get user choice and invoke appropriate action on editor and window.
// If user quits, return false, otherwise return true.
bool user_action(image_editor* editor) {
    string answer;
    bool no_answer = true;

    while (no_answer) {
        show_menu(*editor);
        cout << "Please make a selection: ";
        getline(cin, answer);
        trim(answer);
    
        if (answer == "l") {
            load_file(*editor);
            return true;
        }

        if (answer == "s") {
            save_file(*editor);
            return true;
        }
        
        if (answer == "q") {
            return false;
        }

        // else presume a number representing an effect
        try {
            int effect = stoi(answer);
            if (effect >= 0 && effect < editor->actions.size()) {
                editor->apply_effect(effect);
                return true;
            }
        }
        catch (invalid_argument e) {
            // do nothing
        }

        // if we get here, then no valid response was given
        cout << "Invalid selection; please try again." << endl;
    }
}

// Display a nice menu of editor action choices.
void show_menu(image_editor& editor) {
    cout << endl;
    cout << "Here are your choices:" << endl;
    for (int i = 0; i < editor.actions.size(); i++) {
        cout << "  [" << i << "] " << editor.actions[i] << endl;
    }
    cout << endl;
    cout << "  [l] load new file" << endl;
    cout << "  [s] save file" << endl;
    cout << "  [q] quit" << endl;
    cout << endl;
}

// Utility function to trim whitespace from ends of a string.
void trim(string& s) {
    while (!s.empty() && isspace(s.back())) s.pop_back();
    while (!s.empty() && isspace(s.front())) s.erase(0, 1);
}

