#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
int n,s;
vector<int> A;

void func1(int index, int sum){
    if(sum == s) cnt++;

    for(int i=index+1;i<=n;i++){
        func1(i, sum + A[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> s;

    A.resize(n+1);


    for(int i=1;i<=n;i++){
        cin >> A[i];
    }

    for(int i=1;i<=n;i++){
        func1(i,A[i]);
    }


    cout << cnt;
    return 0;
}