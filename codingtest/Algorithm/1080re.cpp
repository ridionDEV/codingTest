#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m));
    vector<vector<int>> B(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<input.length();j++){
            A[i][j] = input[j] - '0';
        }
    }
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<input.length();j++){
            B[i][j] = input[j] - '0';
        }
    }
    int cnt = 0;

    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(A[i][j] != B[i][j]){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(A[k][l] == 0)
                            A[k][l] = 1;
                        else
                            A[k][l] = 0;
                    }
                }
                cnt++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] != B[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;
    return 0;
}