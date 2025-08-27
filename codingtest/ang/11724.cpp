#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> node;
vector<bool> visited;

void dfs(int start){

    visited[start] = true;

    for(int next : node[start]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    node.resize(n+1);
    visited = vector<bool>(n+1,false);

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    int result = 0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            result++;
            dfs(i);
        }
    }

    cout << result;

}