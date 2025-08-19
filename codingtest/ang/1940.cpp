#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int x = 0;
    int y = n-1;

    int cnt = 0;

    while(x < y){
        if(arr[x] + arr[y] == m){
            cnt++;
            x++;
            y--;
        }
        else if(arr[x] + arr[y] > m){
            y--;
        }
        else if(arr[x] + arr[y] < m){
            x ++ ;
        }
    }

    cout << cnt << endl;

    return 0;
}