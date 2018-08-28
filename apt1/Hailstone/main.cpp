#include <string>
#include <iostream>

using namespace std;

string sequence(int n) {
    string toReturn = to_string(n) + " ";
    while(n != 1){
        if(n%2 == 0){ //n is even
            n/=2;
        }
        else if(n%2 == 1){ //n is odd
            n*=3;
            n+=1;
        }
        cout << n << endl;
        toReturn += to_string(n) + " ";
    }
    toReturn.erase(toReturn.end() - 1);
    return toReturn;
}


int main() {

    cout << sequence(17) << endl;

    return 0;

}