#include <iostream>
#include <vector>
using namespace std;

int count(int n,int m,int x,vector<vector<int>> board){
    int count = 0;

    for(int i=n;i<n+8;i+=2){
        for(int j=m;j<m+8;j+=2){
            if(x==0 && board[i][j]==1){
                count++;
            }
            else if(x==1 && board[i][j]==0){
                count++;
            }
        }

        for(int k=m+1;k<m+8;k+=2){
            if(x==0 && board[i][k]==0){
                count++;
            }
            else if(x==1 && board[i][k]==1){
                count++;
            }
        }
    }

    for(int i=n+1;i<n+8;i+=2){
        for(int j=m;j<m+8;j+=2){
            if(x==0 && board[i][j]==0){
                count++;
            }
            else if(x==1 && board[i][j]==1){
                count++;
            }
        }

        for(int k=m+1;k<m+8;k+=2){
            if(x==0 && board[i][k]==1){
                count++;
            }
            else if(x==1 && board[i][k]==0){
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    vector<vector<int>> board(n,vector<int>(m));

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++){
            if(input[j]=='B')
                board[i][j]=0;
            else
                board[i][j]=1;
        }
    }

    int result = 987654321;

    for(int i=0;i<=n-8;i++){
        for(int j=0;j<=m-8;j++){
            int cnt = min(count(i,j,0,board),count(i,j,1,board));
            result = min(result,cnt);
        }
    }


    cout << result;
    return 0;
}