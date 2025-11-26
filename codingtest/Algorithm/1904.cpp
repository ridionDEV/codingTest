#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    int dp[N+1];

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N] % 15746;

    return 0;
}