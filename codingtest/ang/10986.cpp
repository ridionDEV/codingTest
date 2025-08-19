#include <iostream>
#include <vector>

using namespace std;



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<long long> S(n+1,0);
    vector<long long> C(m,0);
    long long result = 0;

    for(int i=1;i<=n;i++){
        int input;
        cin >> input;
        S[i] = (S[i-1] + input);
    }

    for(int i=1;i<=n;i++){
        int remain = S[i] % m;
        if(remain == 0) result ++;

        C[remain]++;
    }

    for(int i=0;i<m;i++){
        if(C[i] > 1)
            result += C[i] * (C[i] - 1) / 2;
    }



    cout << result << endl;

    return 0;
}