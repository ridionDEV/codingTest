#include <iostream>
using namespace std;

int main(void){
    int n;
    while(cin >> n){
        long long v = 1;
        short count = 1;

        while(v%n!=0){
            v = ((v*10)+1)%n;
            count++;
        }
        cout << count << '\n';
        
    }
}