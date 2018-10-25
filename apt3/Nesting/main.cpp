#include <string>
#include <queue>
#include <iostream>

using namespace std;

bool is_valid(string expr, string left, string right) {
    queue<int> myQ;
    for(int i=0; i<expr.length(); i++){
        for(int j=0; j<left.length(); j++){
            if(expr[i] == left[j]){
                myQ.push(i);
            }
            if(expr[i] == right[j]){
                if(myQ.empty()){
                    return false;
                }
                else if(right[j] != right[myQ.front()]){
                    return false;
                }
                myQ.pop();
            }

        }
    }
    return true;

}

int main(){
    cout << is_valid("abc(def)ghi", "(", ")") << endl;


    return 0;
}
