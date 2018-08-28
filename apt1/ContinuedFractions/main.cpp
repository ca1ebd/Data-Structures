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
    vector<int> coeffs;

    do{
        int coeff;
//        if(den!=0){
//            coeff = num/den;
//        }

        coeff = num/den;

        num -= coeff*den;
        coeffs.push_back(coeff);
        //switch variables
        int temp = num;
        num = den;
        den = temp;
        if(den == 1){
            coeff = num/den;
            num -= coeff*den;
            coeffs.push_back(coeff);
        }
    } while((den != 1) and (den != 0));
    string toReturn = "[";
    toReturn+=to_string(coeffs[0]) + ";";
    for(int i=1; i<coeffs.size(); i++){
        toReturn += to_string(coeffs[i]) + ",";
    }
    toReturn.erase(toReturn.end() - 1);
    toReturn+= "]";
    return toReturn;
}



int main() {

    cout << cfrac(368, 56);

    return 0;
}