#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> node;
bool Find = false;

bool visited[2000] = {false};

void dfs(int start,int cnt){

    if(cnt == 5){
        Find = true;
        return;
    }

    for(int next : node[start]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next,cnt+1);
        }
    }

    visited[start] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    node.resize(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;

        node[x].push_back(y);
        node[y].push_back(x);
    }

    for(int i=0;i<n;i++){
        visited[i] = true;
        dfs(i,1);

        if(Find){
            cout << 1;
            return 0;
        }
    }
    
    cout << 0;


    return 0;
}