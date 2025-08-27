#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using Pair = pair<long long, long long>;

int main(){

    int n;
    cin >> n;
    priority_queue<long long,vector<long long>, greater<long long>> pq;
    vector<Pair> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    pq.push(A[0].second);

    for(int i=1;i<n;i++){

        if(A[i].first >= pq.top()){
            pq.pop();
        }
        pq.push(A[i].second);
    }

    cout << pq.size() << endl;


    return 0;
}