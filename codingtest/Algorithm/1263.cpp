#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i].first >> A[i].second;
        if(A[i].second < A[i].first){
            cout << -1;
            return 0;
        }
    }

    sort(A.begin(),A.end(),[](pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    });

    int start = A[0].second - A[0].first;
    int now = A[0].second;

    for(int i=1;i<n;i++){
        while(now + A[i].first > A[i].second){
            start--;
            now--;

            if(start < 0){
            cout << -1;
            return 0;
            }
        }

        now += A[i].first;


    }

    cout << start;

    return 0;
}