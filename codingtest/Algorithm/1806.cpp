#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    long long S[100000] = {};
    for(int i=1;i<=n;i++){
        long long input;
        cin >> input;

        S[i] = S[i-1] + input;
    }

    int result = 98765432;

    int x=1;
    int y=1;

    bool isTrue = false;

    while(y <= n){

        if(S[y]-S[x-1] >= m){
            if(y-x+1 <= result)
                result = y-x + 1;
            
            x++;
            isTrue = true;

            if(x>y) y++;

            if(result == 1) break;
        }
        else{
            y++;
        }
    }

    if(isTrue)
        cout << result << endl;
    else
        cout << 0 << endl;

    return 0;
}