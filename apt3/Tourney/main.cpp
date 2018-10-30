#include <vector>
#include <string>
#include <queue>
#include <iostream>


using namespace std;

string winner(vector<string> bracket, string results) {
    queue<string> myBracket;
    for(int i=0; i<bracket.size(); i++){
        myBracket.push(bracket[i]);
    }

    int gameCount = 0;
    string firstContestant = "";
    string secondContestant = "";
    while(myBracket.size() > 1) {
        firstContestant = myBracket.front();
        myBracket.pop();
        secondContestant = myBracket.front();
        myBracket.pop();

        //cout << "First contestant: " << firstContestant << endl;
        //cout << "Second contestant: " << secondContestant << endl;

        //if either value is bye, push to the back of the queue
        if (firstContestant == "bye") {
            //cout << "first contestant was a bye" << endl;
            myBracket.push(secondContestant);
            continue;
        } else if (secondContestant == "bye") {
            //cout << "second contestant was a bye" << endl;
            myBracket.push(firstContestant);
            continue;
        } else if (results[gameCount] == 'L') {
            //cout << secondContestant << " won!" << endl;
            myBracket.push(secondContestant);
            gameCount++;
        } else if (results[gameCount] == 'H') {
            //cout << firstContestant << " won!" << endl;
            myBracket.push(firstContestant);
            gameCount++;
        }
    }
    return myBracket.front();
}

int main(){
    vector<string> testVec({"A","B","C","bye","D","E","F","bye"});
    string testResult = "LHHLH";
    cout << winner(testVec, testResult) << endl;

    return 0;
}