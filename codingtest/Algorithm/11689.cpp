#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long n;
    cin >> n;

    long long result = n;

    for(long long i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            result = result - (result/i);
        }
    }

    cout << result;
    return 0;
}