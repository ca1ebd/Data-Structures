#include <string>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

bool is_valid(string expr, string left, string right) {
    stack<int> myStack;
    bool closed = false;
    for(int i=0; i<expr.length(); i++){
        for(int j=0; j<left.length(); j++){
            if(expr[i] == left[j]){
                myStack.push(j);
                closed = false;
            }
            if(expr[i] == right[j]){
                if(myStack.empty()){
                    return false;
                }
                else if(right[j] != right[myStack.top()]){
                    return false;
                }
                else if(right[j] == right[myStack.top()]){
                    myStack.pop();
                    closed = true;
                }

            }

        }
    }

    return closed;

}

int main(){
    cout << is_valid("(x(x)", "(", ")") << endl;


    return 0;
}
