#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    int board[100][100] = {0};
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++){
            board[i][j] = input[j] - '0';
        }
    }


    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};


    
    queue<pair<int,int>> q; 

    bool visited[100][100] = {false};

    visited[0][0] = true;
    
    q.push({0,0});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;

        
        q.pop();

        for(int i=0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || board[nextX][nextY] != 1) continue;

            if(!visited[nextX][nextY]){
                visited[nextX][nextY] = true;
                board[nextX][nextY] = board[curX][curY] + 1;
                q.push({nextX,nextY});
            }
        }


    }

    cout << board[n-1][m-1];

    return 0;
}