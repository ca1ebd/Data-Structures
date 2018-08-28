#include <string>
#include <iostream>

using namespace std;

double ratio(string dna) {
    int countCG = 0;
    for(int i=0; i<dna.length(); i++){
        if((dna[i] == 'c') or (dna[i] == 'g')){
            countCG++;
        }
    }
    return static_cast<double>(countCG) / static_cast<double>(dna.length());
}

int main() {

    cout << ratio("agatc");
    return 0;
}