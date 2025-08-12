#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> edge;
vector<vector<edge>> node;
vector<int> dist;

int v;
int maxDist = 1;

void bfs(int start){
    bool visited[100001] = {false};
    dist = vector<int>(v+1,0);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){

        int now = q.front(); q.pop();

        for(edge next : node[now]){
            if(!visited[next.first]){
                visited[next.first] = true;
                q.push(next.first);

                dist[next.first] = dist[now] + next.second;
            } 
        }
    }


    for(int i=2;i<=v;i++){
        if(dist[maxDist] < dist[i]){
            maxDist = i;
        }
    }
}

int main(void){

    

    cin >> v;
    node.resize(v+1);

    for(int i=0;i<v;i++){
        int input;
        cin >> input;

        int x,y;
        while(cin >> x && x != -1){
            cin >> y;

            node[input].push_back(edge(x,y));
        }

    }

    bfs(1);

    bfs(maxDist);
    
    sort(dist.begin(),dist.end());

    cout << dist[v] << endl;

    return 0;
}