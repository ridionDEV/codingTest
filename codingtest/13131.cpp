#include <iostream>
#include <iomanip>
using namespace std;

const long double kg_per_lbs = 2.20462L;

long double operator"" _kg(long double value){
    return value;
}

long double operator"" _lbs(long double value){
    return value * kg_per_lbs;
}

int main(void) {
    long double distance_1 = 1.0_kg;
    long double distance_2 = 3.2_lbs;

    cout << distance_2 << endl;
}

