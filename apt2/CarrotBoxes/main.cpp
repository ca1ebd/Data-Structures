//
// Created by calebdudley on 9/20/2018.
//

#include <vector>
#include <iostream>

using namespace std;

int last_box(vector<int> &carrots, int amount) {
    int max = 0;
    int maxIndex = 0;
    for(int i=0; i<amount; i++){ //"eat" amount carrots
        max = carrots[0];
        maxIndex = 0;
        for(int j=0; j<carrots.size(); j++){
            if(carrots[j] > max){
                max = carrots[j];
                maxIndex = j;
            }

        }
        carrots[maxIndex]--;

    }
    return maxIndex;
}

int main() {

    vector<int> testVec = {4, 9, 5};
    int testAmount = 18;
    cout << last_box(testVec, testAmount);


    return 0;
}



