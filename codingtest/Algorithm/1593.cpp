#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,m;
    int result = 0;
    cin >> n >> m;

    string w,s;
    cin >> w >> s;

    vector<int> need(128,0);
    vector<int> have(128,0);

    for(char c : w) need[c]++;

    for(int i=0;i<n;i++){
        
    }

    int x = 0;
    int y = n-1;

    while(y < m){

    }







    cout << result;

    return 0;
}