#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,d;
    cin >> n >> d;

    int result = 987654321;
    vector<vector<int>> A(n,vector<int>(3,987654321));

    int dp[n][2];

    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;

        if(b > d || (b-a)-c <= 0){
            continue;
        }

        A[i][0] = a;
        A[i][1] = b;
        A[i][2] = (b-a)-c;
    }
    
    sort(A.begin(),A.end());

    dp[0][0] = A[0][0] + A[0][2];
    dp[0][1] = A[0][1];

    for(int i=1;i<n;i++){

        if(A[i][1] > d || A[i][2] < 0){
            int a = min(A[i-1][0], )
            cout << min(dp[i-1][0] + (d-A[i-1][1]), dp[i-1][1] + (d-A[]));
            return;
        }

        if(A[i][0] >= A[i-1][1]){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + (A[i][0] - A[i-1][1]) + A[i][2];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (A[i][0] - A[i-1][1]);
        }
        else{
            dp[i][0] = dp[i-1][1] + (A[i][0] - A[i-1][0]) + A[i][2];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1] + A[i-1][2]);  //dp[i-1][1] + (A[i][0] - A[i-1][1]);
        }
        
    }
    return 0;
}