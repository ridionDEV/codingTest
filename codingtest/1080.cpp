#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static int n,m;
    

void flip3x3(vector<vector<int>> &arr, int x, int y){
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++){
            arr[i][j] ^= 1;
        }
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++){
            a[i][j] = input[j] - '0';
        }
    }

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0;j<m;j++){
            b[i][j] = input[j] - '0';
        }
    }

    int count = 0;
    for(int i=0;i <= n -3 ;i ++){
        for(int j=0; j<= m-3;j++){
            if(a[i][j] != b[i][j])
            {
                flip3x3(a,i,j);
                count++;
            }
        }
    }

    bool same = true;
    for(int i=0; i < n && same; i++){
        for(int j=0; j < m && same ; j++){
            if(a[i][j] != b[i][j])
            {
                same = false;
            }
        }
    }

    cout << (same ? count : -1) << endl;
    

    return 0;
}
