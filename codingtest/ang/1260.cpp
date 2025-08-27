#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> node;
bool visited[1001] = {false};

void dfs(int now){

    cout << now << " ";

    for(int next : node[now]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
}

void bfs(int start){
    bool visited[1001] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int current = q.front(); q.pop();
        cout << current << " ";

        for(int next : node[current]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m,v;
    cin >> n >> m>>v;
    node.resize(n+1);

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(node[i].begin(),node[i].end());
    }

    visited[v]= true;
    dfs(v);
    cout << '\n';
    bfs(v);


    return 0;
}