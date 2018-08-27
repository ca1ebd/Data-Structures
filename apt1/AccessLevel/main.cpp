#include <vector>
#include <iostream>

using namespace std;


string can_access(vector<int> &user_rights, int min_permission) {
    string permissions = "";

    for(int i=0; i<user_rights.size(); i++){
        if (user_rights[i] >= min_permission){
            permissions += "A";
        }
        else{
            permissions += "D";
        }
    }

    return permissions;
}


int main() {

    vector<int> testData;

    testData.push_back(5);
    testData.push_back(4);
    testData.push_back(9);

    cout << can_access(testData, 5) << endl;

    return 0;
}