#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    cin >> n;

    vector<int> A(n,0);

    for(int i= 0;i <n ;i++){
        cin >> A[i];
    }

    cin >> m;

    sort(A.begin(),A.end());

    int x = 0;
    int y = n-1;

    int cnt = 0;

    while(y > x){

        if(A[x] + A[y] == m){
            cnt++;
            x++;
            y--;
        }
        else if(A[x] + A[y] < m){
            x++;
        }
        else if(A[x] + A[y] > m){
            y--;
        }
    }

    cout << cnt << endl;

    return 0;

}