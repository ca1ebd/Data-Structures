#include <iostream>

using namespace std;

int main() {

    int first, second, left, right;
    cout << "Please enter two numbers: ";
    cin >> first;
    cin >> second;

    if(first < second){
        left = first;
        right = second;
    }
    else{
        left = second;
        right = first;
    }
    //cout << left << right << endl;
    int sum = 0;

    //add value to answer
    while (left >= 1){
        cout << left << " " << right << endl;
        if((left%10)%2==1){
            sum += right;
        }
        left/=2;
        right+=right;
    }

    cout << "Answer: " << sum << endl;

    return 0;
}