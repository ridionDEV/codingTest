#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> arr;

void bfs(long long num,int digit){
    arr.push_back(num);
    for(int i=0;i<digit;i++){
        bfs(num * 10 + i,i);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<10;i++){
        bfs(i,i);
    }

    sort(arr.begin(),arr.end());
    
    if(n >= arr.size()) cout << -1 << endl;
    else cout << arr[n] << endl;

    
    return 0;
}