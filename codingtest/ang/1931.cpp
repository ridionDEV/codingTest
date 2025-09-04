#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pq.push({y,x});
    }

    int cnt = 0;

    int now = pq.top().first;
    cnt++;
    pq.pop();

    while(!pq.empty()){
        if(now <= pq.top().second){
            cnt++;
            now = pq.top().first;
        }
        pq.pop();
    }


    cout << cnt;

    return 0;
}