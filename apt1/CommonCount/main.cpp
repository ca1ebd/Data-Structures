#include <string>
#include <iostream>

using namespace std;

int count(string a, string b) {
    int count = 0;
    for(int i=0; i<a.length(); i++){
        for(int j=0; j<a.length(); j++){
            if((static_cast<char>(a[i]) == static_cast<char>(b[j])) and a[i] != '@'){
                count++;
//                cout << a[i] << endl;
//                cout << b[j] << endl;
                a[i] = '@';
                b[j] = '@';
//                a.erase(i, 1);
//                b.erase(j, 1);
            }
        }
    }

//    cout << a << endl;
//    cout << b << endl;
    return count;
}

int main() {

    cout << count ("horse", "short") << endl;

    return 0;
}