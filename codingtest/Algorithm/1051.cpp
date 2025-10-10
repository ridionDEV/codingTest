#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;

    cin >> n >> m;

    vector<vector<int>> A(n,vector<int>(m));

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            A[i][j] = s[j] - '0';
        }
    }

    int result = 0;

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){

            int temp = 1;

            int maxSize = min(n-y,m-x);

            for(int i=1;i<maxSize;i++){
                
                if(A[y][x] == A[y+i][x] && A[y][x] == A[y][x+i] && A[y][x]== A[y+i][x+i]){
                    temp = (i+1)*(i+1);
                }
            }

            result = max(result, temp);
        }
    }


    cout << result;
    return 0;
}