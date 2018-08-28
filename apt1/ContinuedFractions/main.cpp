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


string recursive_frac(int num, int den){
    int coeff = num/den;
    num -= coeff*den;
    if(den == 1){
        return to_string(coeff);
    }

    return to_string(coeff) + recursive_frac(den, num);
}

string cfrac(int num, int den) {
    string base_string = recursive_frac(num, den);
    return "[" + base_string.substr(0, 1) + ";" + base_string.substr(1, base_string.length() - base_string.back()) + "]";
//    return recursive_frac(num, den);

}



int main() {

    cout << cfrac(421, 36);

    return 0;
}