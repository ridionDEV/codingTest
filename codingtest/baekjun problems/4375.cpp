#include <iostream>
using namespace std;

int main(void){
    int n;
    while(cin >> n){
        int v = 1;
        int count = 1;

        while(v%n!=0){
            v = ((v*10)+1)%n;
            count++;
        }
        cout << count << '\n';
    }
}