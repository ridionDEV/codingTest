#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;



int main(void){

    ll a,b;
    cin >> a >> b;

    vector<bool> isNotSquare(b-a+1,true);

    for(ll i=2;i<=sqrt(b);i++){
        ll square = i*i;
        ll start = ((a + square -1)/square) * square;
        for(ll j=start;j<=b;j+=square){
            isNotSquare[j-a] = false;
        }
    }
    ll count =0 ;
    for(bool b : isNotSquare){
        if(b==true) count ++;
    }
    cout << count << endl;
    return 0;
}