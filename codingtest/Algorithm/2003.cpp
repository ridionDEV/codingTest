#include <iostream>

using namespace std;

int main(){

    int n;
    long long m;
    int cnt = 0;
    cin >> n >> m;

    long long S[10001] = {};

    for(int i=1;i<=n;i++){
        long long input;
        cin >> input;

        S[i] = S[i-1] + input;
    }

    int x = 1;
    int y = 1;

    while(y <= n){
        if(S[y] - S[x-1] == m){
            cnt++;
            x++;

            if(x>y) y++;
        }
        else if(S[y] - S[x-1] < m){
            y++;
        }
        else if(S[y] - S[x-1] > m){
            x++;
        }
    }

    cout << cnt << endl;

    return 0;
}