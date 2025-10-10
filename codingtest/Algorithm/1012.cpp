#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int m,n,k;
        cin >> m >> n >> k;
        vector<vector<int>> A(m, vector<int>(n,0));

        int cnt = 0;
        bool visited[50][50] = {false};

        for(int j=0;j<k;j++){
            int x,y;
            cin >> x >> y;

            A[x][y] = 1;
        }

        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){

                if(A[x][y] == 1 && visited[x][y] == false){

                    queue<pair<int,int>> q;

                    q.push({x,y});
                    visited[x][y] = true;
                    cnt++;

                    while(!q.empty()){

                        int ax = q.front().first;
                        int ay = q.front().second;

                        q.pop();

                        for(int i=0;i<4;i++){

                            int nx = ax+dx[i];
                            int ny = ay+dy[i];

                            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                                if(A[nx][ny] == 1 && visited[nx][ny] == false){
                                    q.push({nx,ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
        }
    return 0;
}