#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<vector<pair<int,int>>> node;




int func1(int start,int end){

    vector<bool> visited(n+1, false);

    vector<int> dist(n+1,0);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        for(auto next : node[cur]){
            if(!visited[next.first]){

                dist[next.first] = dist[cur] + next.second;

                q.push(next.first);
                visited[next.first] = true;
                

                if(next.first == end)
                    return dist[next.first];
            }

            
        }
    }

    return -1;
}

int main(void){

    cin >> n >> m;

    node.resize(n+1);

    for(int i=0;i<n-1;i++){
        int x,y,z;

        cin >> x >> y >> z;

        node[x].push_back(pair(y,z));
        node[y].push_back(pair(x,z));
    }

    for(int i=0;i<m;i++){
        int x,y;

        cin >> x >> y;

        cout << func1(x,y) << endl;
    }


    return 0;
}