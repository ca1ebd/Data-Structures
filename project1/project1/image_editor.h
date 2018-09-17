#ifndef _IMAGE_EDITOR_H
#define _IMAGE_EDITOR_H

/*
    image_editor.h
        
    Class definition for the image_editor class.

    author: C. Painter-Wakefield

    last modified: 1/15/2018
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;


/******************************************************************************
   class image_editor

   Given the filename of a file containing PPM image data, an image_editor 
   object can:
     - read in initial image data from an input stream
     - write out the current image data to an output stream
     - provide the dimensions of the image
     - provide image color data on a per-pixel basis
     - provide a list of effects that can be applied to an image
     - apply a selected image effect to the current image

******************************************************************************/

class image_editor {
public:
    // load and save
    bool load(istream& in);
    void save(ostream& out);

    // access dimensions
    int get_rows();
    int get_columns();

    // access pixel data
    int get_red(int row, int col);
    int get_green(int row, int col);
    int get_blue(int row, int col);

    // apply image editor effect by index (see below)
    void apply_effect(int action_index);

    // this enumerated type will be used to map menu items to actions; add
    // any additional effects here, and a text description (in the same 
    // order) to the vector below.
    enum action {
        GRAYSCALE,
        NEGATE_RED,
        NEGATE_GREEN,
        NEGATE_BLUE,
        FLATTEN_RED,
        FLATTEN_GREEN,
        FLATTEN_BLUE,
        EXTREME_CONTRAST,
        FLIP_HORIZONTAL,
        FLIP_VERTICAL,
        ENLARGE,
        REDUCE,
        ROTATE
    };

    const vector<string> actions = {
        "convert to grayscale",
        "negate red",
        "negate green",
        "negate blue",
        "flatten red",
        "flatten green",
        "flatten blue",
        "extreme contrast",
        "flip horizontally",
        "flip vertically",
        "enlarge",
        "reduce",
        "rotate"
    };
    
private:
    int rows, cols;
    vector<vector<vector<int>>> imageVec;
    // TODO: declare private member variables for holding
    // rows, columns, and image data
    void make_grayscale();
    void make_neg_red();
    void make_neg_green();
    void make_neg_blue();
    void make_flat_red();
    void make_flat_green();
    void make_flat_blue();
    void make_ext_contrast();
    void flip_horizontal();
    void flip_vertical();
    void enlarge();
    void reduce();
    void rotate();

    // TODO: declare methods to apply effects to image
};

#endif
