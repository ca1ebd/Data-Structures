#include <string>
#include <vector>
#include <iostream>

using namespace std;

//string cfrac(int num, int den) {
//    vector<int> coeffs;
//    double remain = -1.0;
//    string build = "";
//    while(remain != 0.0){
//        int coeff = num/den;
//        remain = static_cast<double>(num) / static_cast<double>(den) - coeff;
//        cout << remain << endl;
//        cout << coeff << endl;
//        cout << endl;
//        coeffs.push_back(coeff);
//    }
//
//    for (int i = 0; i < coeffs.size(); ++i) {
//        build += coeffs[i];
//    }
//
//    return build;
//
//}



string cfrac(int num, int den) {
    int coeff = num/den;
    num -= coeff*den;
    if(den == 1){
        return to_string(coeff);
    }

    return to_string(coeff) + cfrac(den, num);

}

int main() {

    cout << cfrac(1, 3);

    return 0;
}