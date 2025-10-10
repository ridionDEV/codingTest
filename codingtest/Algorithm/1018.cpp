#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    vector<vector<char>> board(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    int result = 987654321;

    for(int y=0;y<=n-8;y++){
        for(int x=0;x<=m-8;x++){

            int b = 0;
            int w = 0;
            
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    char B = ((i+j)%2==0) ? 'B' : 'W';

                    if(board[y+i][x+j]!=B) b++;
                    else w++;
                }
            }

            result = min(result,min(b,w));
        }
    }


    cout << result;
    return 0;
}