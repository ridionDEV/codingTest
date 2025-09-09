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

    for(int i=0;i<n-1;i++){
        if(A[i+1]-A[i] != 0){
            pq.push({A[i+1]-A[i],i});
        }
    }

    vector<int> B;
    int gap = min((int)pq.size(), k-1);
    for(int i=0;i<gap;i++){
        B.push_back(pq.top().second);
        pq.pop();
    }
    
    sort(B.begin(),B.end());

    int result = 0;
    int start = 0;
    for(int v : B){
        result += A[v] - A[start];
        start = v + 1;
    }
    
    result += A[n-1] - A[start];

    cout << result;
    return 0;
}