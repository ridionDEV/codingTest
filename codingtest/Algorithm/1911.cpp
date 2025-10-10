#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,l;

    cin >> n >> l;

    vector<pair<int,int>> A(n);
    
    for(int i=0;i<n;i++){
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(),A.end());

    long long now = A[0].first-1;
    int cnt = 0;

    for(int i=0;i<n;i++){

        while(A[i].second-1 > now){
            now += l;
            cnt++;
        }

        if(i==n-1) break;

        if(A[i+1].first > now) now = A[i+1].first -1;
    }

    cout << cnt;
    return 0;
}