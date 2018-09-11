/*
        image_editor.cpp
        
        Method implementations for the image_editor class.

        author: C. Painter-Wakefield

        last modified: 1/15/2018
*/

#include "image_editor.h"

using namespace std;

bool image_editor::load(istream& in) {
    // test magic string
    string magic;
    in >> magic;
    if (magic != "P3") return false;

    string rowsString;
    string colsString;
    in >> colsString;
    in >> rowsString;
    rows = stoi(rowsString);
    cols = stoi(colsString);
//    cout << "Columns: " << cols << endl;
//    cout << "Rows: " << rows << endl;
    // TODO: ensure valid
    string trash;
    in >> trash; //discard?
    // TODO: get and discard color depth

    string temp;


    vector<vector<vector<int>>> tempVec(rows, vector<vector<int>>(cols, vector<int>(3)));
    imageVec = tempVec;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            for(int k=0; k<3; k++){
                in >> temp;
                //cout << "ran";
                imageVec[i][j][k] = stoi(temp);
            }
        }
    }

    // TODO: initialize your image storage data structure

    // TODO: get image data from input stream into your data structure

    return true;
}

void image_editor::save(ostream& out) {
    // TODO: output valid PPM file format data to the
    // output stream out
    out << "P3" << endl;
    out << cols << " " << rows << endl;
    out << "255" << endl;

    //fill with data from imageVec
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            for(int k=0; k<3;k++){
                out << imageVec[i][j][k] << " ";
            }
            out << " ";
        }
        out << endl;
    }

}

int image_editor::get_rows() {
    return rows;
}

int image_editor::get_columns() {
    return cols;
}

int image_editor::get_red(int row, int col) {
    // TODO: return the actual pixel red value
    return imageVec[row][col][0];
}

int image_editor::get_green(int row, int col) {
    // TODO: return the actual pixel green value
    return imageVec[row][col][1];
}

int image_editor::get_blue(int row, int col) {
    // TODO: return the actual pixel blue value
    return imageVec[row][col][2];
}

void image_editor::apply_effect(int action_index) {
    enum action a = (enum action)action_index;

    // TODO: fill out this method
    if (a == GRAYSCALE) {
        make_grayscale();
    }
    else if (a == NEGATE_RED) {
        make_neg_red();
    }
    else if (a== NEGATE_GREEN) {
        make_neg_green();
    }
    else if (a == NEGATE_BLUE){
        make_neg_blue();
    }
    else if(a == FLATTEN_RED){
        make_flat_red();
    }
    else if(a == FLATTEN_GREEN){
        make_flat_green();
    }
    else if(a == FLATTEN_BLUE) {
        make_flat_blue();
    }
    else if (a== EXTREME_CONTRAST){
        make_ext_contrast();
    }
    else if (a == FLIP_HORIZONTAL){
        flip_horizontal();
    }
    else if (a == FLIP_VERTICAL){
        flip_vertical();
    }
}

//custom effects
void image_editor::make_grayscale(){
    int avg;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            avg = (imageVec[i][j][0] + imageVec[i][j][1] + imageVec[i][j][2])/3;
            for(int k=0; k<3; k++){
                imageVec[i][j][k] = avg;
            }
        }
    }
}

void image_editor::make_neg_red(){
    int neg_val;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            neg_val = 255 - imageVec[i][j][0];
            imageVec[i][j][0] = neg_val;
        }
    }
}

void image_editor::make_neg_green(){
    int neg_val;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            neg_val = 255 - imageVec[i][j][1];
            imageVec[i][j][1] = neg_val;
        }
    }
}

void image_editor::make_neg_blue(){
    int neg_val;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            neg_val = 255 - imageVec[i][j][2];
            imageVec[i][j][2] = neg_val;
        }
    }
}

void image_editor::make_flat_red(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            imageVec[i][j][0] = 0;
        }
    }
}

void image_editor::make_flat_green(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            imageVec[i][j][1] = 0;
        }
    }
}

void image_editor::make_flat_blue(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            imageVec[i][j][2] = 0;
        }
    }
}

void image_editor::make_ext_contrast(){
    int midpoint = 255/2;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            for(int k=0; k<3; k++){
                if(imageVec[i][j][k] <= midpoint){
                    imageVec[i][j][k] = 0;
                }
                else {
                    imageVec[i][j][k] = 255;
                }
            }
        }
    }
}

void image_editor::flip_horizontal(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols/2; j++){
            vector<int> tempColumn;
            tempColumn = imageVec[i][j];
            imageVec[i][j] = imageVec[i][cols-j-1];
            imageVec[i][cols-j-1] = tempColumn;
        }
    }
}

void image_editor::flip_vertical(){
    for(int i=0; i<rows/2; i++){
        for(int j=0; j<cols; j++){
            vector<int> tempColumn;
            tempColumn = imageVec[i][j];
            imageVec[i][j] = imageVec[rows-i-1][j];
            imageVec[rows-i-1][j] = tempColumn;
        }
    }
}

// TODO: add effect methods below here


