#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static int solve = 0;

void bfs(int x, int y, vector<vector<int>> &_board){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    queue<pair<int,int>> q;

    q.push({x,y});

    int count = 1;
    
    while(!q.empty()){
        
        int currentX = q.front().first;
        int currentY = q.front().second;

        q.pop();

        for(int k=0;k<4;k++){
            if(currentX+dx[k] >= 0 && currentX+dx[k] <= _board.size()-1 && currentY+dy[k] >= 0 && currentY+dy[k] <= _board[0].size()-1){ //범위 벗어나지 않게 제한
                if(_board[currentX+dx[k]][currentY+dy[k]]==1)
                {
                    _board[currentX+dx[k]][currentY+dy[k]] = 2;
                    count++;
                    q.push({currentX+dx[k],currentY+dy[k]});

                }
            }
        }
    }


    solve = max(solve,count);
    
}


int main(void){
    int n,m,k;

    cin >> n >> m >> k;

    vector<vector<int>> board(n, vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){ // 0으로 초기화
            board[i][j] = 0;
        }

    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        board[a-1][b-1] = 1; //쓰레기 1로 설정
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                board[i][j] = 2; //방문한 쓰레기는 2로 설정
                bfs(i,j,board);
            }
        }
    

    cout << solve << endl;
    return 0;
}