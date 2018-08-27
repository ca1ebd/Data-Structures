#include <string>
#include <iostream>

using namespace std;

int count(string a, string b) {
    int count = 0;
    for(int i=0; i<a.length(); i++){
        for(int j=0; j<a.length(); j++){
            if(static_cast<char>(a[i]) == static_cast<char>(b[j])){
                count++;
                cout << a[i] << endl;
                cout << b[j] << endl;
                a.erase(i);
                b.erase(j);
            }
        }
    }

    cout << a << endl;
    return count;
}

int main() {

    cout << count ("hello", "world") << endl;

    return 0;
}