#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n,k;

    cin >> n >> k;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    priority_queue<pair<int,int>> pq;

    for(int i=1;i<n;i++){
        if(A[i]-A[i-1] != 0){
            pq.push({A[i]-A[i-1],i});
        }
    }

    vector<int> B(k-1);
    for(int i=0;i<k-1;i++){
        B[i] = (pq.top().second);
        pq.pop();
    }

    sort(B.begin(),B.end());

    int result = 0;
    int start = 0;
    for(int value : B){
        result += A[value-1] - A[start];
        start = value;
    }


    cout << result;
    return 0;
}