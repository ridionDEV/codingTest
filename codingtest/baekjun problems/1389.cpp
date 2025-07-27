#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,m;

int value[101]={0};

int minimum  = INT_MAX;
int answer;

void bfs(int start,vector<vector<int>> &_node){
    int dist[101]={-1};
    bool visit[101] ={false};
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    visit[start] = true;

    while(!q.empty()){
        int current = q.front();
        
        q.pop();
        for(int next : _node[current]){
            if(visit[next]==false){
                q.push(next);
                dist[next] = dist[current] + 1;
                visit[next] = true;
                value[start] += dist[next];
            }
        }
    }

    if(minimum > value[start]){
        minimum = value[start];
        answer = start;
    }
}

int main(void){
    cin >> n >> m;
    vector<vector<int>> node(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        bfs(i,node);
    }

    cout << answer << endl;

    return 0;
}