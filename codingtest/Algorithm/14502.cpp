#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> board;
int demo = 0;
int v;
int result = 0;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void dfs(int startX,int startY, bool visited[8][8]){
    v = 0;
    queue<pair<int,int>> q;

    q.push({startX,startY});
    visited[startX][startY] = true;

    while(!q.empty()){

        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        

        for(int i=0;i<4;i++){

            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= m || board[nextX][nextY] != 0 || visited[nextX][nextY]==true) continue;

            visited[nextX][nextY] = true;
            q.push({nextX,nextY});
            v++;
        }
    }
}

void func1(int cnt){

    if(cnt == 3){
        int temp = demo - 3;
        bool visited[8][8] = {};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(board[i][j] == 2){
                    
                    dfs(i,j,visited);
                    temp -= v;
                }
            }

        result = max(result,temp);
        
        
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 0){

                board[i][j] = 1;

                func1(cnt+1);

                board[i][j] = 0;
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> n >> m;

    board = vector<vector<int>>(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 0) demo++;
        }
    }

    func1(0);



    cout << result;
    return 0;
}