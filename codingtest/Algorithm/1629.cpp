#include <iostream>
using namespace std;

long long func1(long long a,long long b,long long c){
    if(b<=1) return a % c;

    long long temp = func1(a,b/2,c);

    if(b % 2 == 0) return (temp * temp) % c;
    else if(b % 2 == 1) return (((temp * temp) % c) * a) % c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long a,b,c;
    cin >> a >> b >> c;

    cout << func1(a,b,c);

    return 0;
}