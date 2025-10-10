#include <iostream>
#include <vector>
using namespace std;

int n,m;
int INF = 1000000000;
vector<vector<int>> bus;
vector<bool> visited;
vector<int> d;

int getIndex(){
    int temp = INF;
    int index = 0;
    for(int i=1;i<=n;i++){
        if(d[i] < temp && visited[i]==false){
            temp = d[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int start){
    for(int i=1;i<=n;i++){
        d[i] = bus[start][i];
    }

    visited[start] = true;

    for(int i=0;i<n-2;i++){
        int current = getIndex();
        visited[current] = true;

        for(int j=1;j<=n;j++){
            if(visited[j] == false){

                d[j] = min(d[j], d[current] + bus[current][j]);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m; //도시,버스
    
    bus.resize(n+1,vector<int>(n+1,INF));
    visited.resize(n+1);
    d.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b,c; //출발,도착,비용
        
        cin >> a >> b >> c;
        
        bus[a][b] = min(bus[a][b], c);
    }
    
    int start,dest;
    cin >> start >> dest;

    
    dijkstra(start);
    

    


    cout << d[dest];
    return 0;
}