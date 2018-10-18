//
// Created by calebdudley on 9/20/2018.
//

#include <vector>
#include <iostream>

using namespace std;

int least_borders(vector<int> &x, vector<int> &y, vector<int> &r,
                  int x1, int y1, int x2, int y2) {
    int count = 0;
    for(int i=0; i<x.size(); i++){
        //int left
        if((x1 > x[i] - r[i]) and (x1 < x[i] + r[i]) and (y1 > y[i] - r[i]) and (y1 < y[i] + r[i])){
            count++;
        }
        if((x2 > x[i] - r[i]) and (x2 < x[i] + r[i]) and (y2 > y[i] - r[i]) and (y2 < y[i] + r[i])){
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> testX = {0, -6, 6};
    vector<int> testY = {0, 1, 2};
    vector<int> testR = {2, 2, 2};
    int x1 = -5;
    int y1 = 1;
    int x2 = 5;
    int y2 = 1;
    cout << least_borders(testX, testY, testR, x1, y1, x2, y2) << endl;


    return 0;
}


