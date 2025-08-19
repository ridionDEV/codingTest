#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    int x = 0;
    int y = n-1;


    pair<int,int> result(0,0);

    long long mini = LLONG_MAX;

    while(y > x){
        long long now = abs(A[x] + A[y]);

        if(mini >= now){
            mini = now;
            result.first = A[x];
            result.second = A[y];

            if(mini == 0) break;
        }

        if(A[x] + A[y] > 0){
            y--;
        }
        else if(A[x] + A[y] < 0){
            x++;
        }

    }

    cout << result.first << " " << result.second << endl;

    return 0;

}