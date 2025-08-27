#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1,0);

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        indegree[y] ++;
    }

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int current = pq.top();
        pq.pop();
        cout << current << " ";

        for(int next : graph[current]){
            indegree[next]--;

            if(indegree[next] == 0) pq.push(next);
        }
    }




    return 0;
}