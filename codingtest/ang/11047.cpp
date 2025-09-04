#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,k;
    cin >> n >> k;

    int now;
    vector<int> coin(n);
    for(int i=0;i<n;i++){
        cin >> coin[i];
        if(coin[i] <= k){
            now = i;
        }
    }

    int count = 0;
    int sum = 0;

    for(int i=now;i>=0;i--){
        while(sum + coin[i] <= k){
            sum += coin[i];
            count ++;
        }
    }

    cout << count;

    return 0;
}