#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool istrue(int num){
    int value = sqrt(num);
    return value*value == num;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    vector<string> board(n);

    int maxNum = -1;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> board[i];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int dx=-n;dx<=n;dx++)
                for(int dy=-m;dy<=m;dy++){
                    if(dx==0 && dy==0) continue;

                    int x=i;
                    int y=j;
                    string str = "";
                    while(x >=0 && x < n && y >=0 && y < m){
                        str += board[x][y];
                        int num = stoi(str);
                        if(istrue(num)){
                            maxNum = max(maxNum, num);
                        }
                        x+=dx;
                        y+=dy;
                    }
                }
    
    cout << maxNum << endl;
    return 0;
}