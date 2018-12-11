//
// Created by calebdudley on 12/10/2018.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Point{
    public:
        friend ostream& operator << (ostream &out, const Point &point){
            out << "(" << point.x << ", " << point.y << ")";
            return out;
        }
        int x;
        int y;
    private:

};

Point find_point(char identifier, vector<string> enc){
    Point result = {0, 0};
    for(int i=0; i<enc.size(); i++){
        for(int j=0; j<enc[i].length(); j++){
            if(enc[i][j] == identifier){
                result = {j, i};
                return result;
            }
        }
    }
}

int num_routes(vector<string> enc) {
    Point rat_loc = find_point('R', enc);
    Point cheese_loc = find_point('C', enc);

    cout << "Rat: " << rat_loc << endl;
    cout << "Cheese: " << cheese_loc << endl;

    return -1;
}

int main() {
    vector<string> enc = {".R...",
                          "..X..",
                          "....X",
                          "X.X.X",
                          "...C."};

    num_routes(enc);
}

