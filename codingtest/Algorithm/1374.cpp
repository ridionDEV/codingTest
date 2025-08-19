#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<pair<long long, long long>> room;

    for(int i=0;i<n;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        room.push_back(pair(b,c));
    }

    sort(room.begin(),room.end());

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(auto r : room){

        long long start = r.first;
        long long end  = r.second;

        if(!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
        
    }

    cout << pq.size() << endl;

    return 0;
}