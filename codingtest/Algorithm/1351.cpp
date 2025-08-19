#include <iostream>
#include <map>

using namespace std;

long long n,p,q;
map<long long, long long> dp;

long long func1(long long x){

    if(x==0) return 1;
    if(x==1) return 2;
    if(dp.count(x)) return dp[x];


    return dp[x] = func1(x/p) + func1(x/q);

}

int main(void){

    cin >> n >> p >> q;

    if(n==0){
        cout << 1 << endl;
        return 0;
    }

    cout << func1(n) << endl;

    return 0;
}