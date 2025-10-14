#include <iostream>
#include <queue>
using namespace std;

int n,m,h;
int dayCount = 0;
int A[100][100][100];

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct info{
    int z,y,x;
};

queue<info> q;

void bfs(){
    
    
    while(!q.empty()){

        int qCount = q.size();
        
        for(int j=0;j<qCount;j++){

            int curZ = q.front().z;
            int curY = q.front().y;
            int curX = q.front().x;

            q.pop();

            for(int i=0;i<6;i++){
                int nextZ = curZ + dz[i];
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];

                if(nextZ >= 0 && nextZ < h && nextY >= 0 && nextY < n && nextX >= 0 && nextX < m){
                    if(A[nextZ][nextY][nextX] == 0){
                        info info = {nextZ,nextY,nextX};
                        A[nextZ][nextY][nextX] = 1;
                        q.push(info);
                    }
                }
            }
        }
        

        if(!q.empty()){
            dayCount ++;
        }
    }

    for(int z=0;z<h;z++){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){

                if(A[z][y][x] == 0){
                    dayCount = -1;
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n >> h;

    for(int z=0;z<h;z++){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                cin >> A[z][y][x];

                if(A[z][y][x] == 1){
                    info info = {z,y,x};
                    q.push(info);
                }
            }
        }
    }
    
    bfs();
    cout << dayCount;

    return 0;
}