#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int main(void){
    struct Pos
    {
        int x=0;
        int y=0;
    };
    
    int n,m;
    int board[100][70];
    bool visit[100][70] = {false};
    int count = 0;
    queue<Pos> q;

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){


            if(visit[i][j]==true) continue;
            bool isTrue = true;
            Pos start = {i,j};
            q.push(start);
            visit[start.x][start.y] = true;

            while(!q.empty()){
                int currentX = q.front().x;
                int currentY = q.front().y;
                q.pop();


                
                for(int k=0;k<8;k++){

                    if(currentX+dx[k] < 0 || currentX+dx[k] >= n || currentY+dy[k] < 0 || currentY+dy[k] >= m) continue; //범위 오류 방지

                    Pos next = {currentX+dx[k], currentY+dy[k]};

                    if(board[next.x][next.y] == board[currentX][currentY] && visit[next.x][next.y]==false){
                        q.push(next);
                        visit[next.x][next.y] = true;
                    }
                    else if(board[next.x][next.y] > board[currentX][currentY]){
                        isTrue = false;
                    };

                }
            }

            if(isTrue) count++;
        }
    
    cout << count << endl;
    return 0;
}