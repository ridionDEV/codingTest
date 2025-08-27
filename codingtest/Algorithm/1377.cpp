#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);;
    for(int i=0;i<n;i++){
        cin >> arr[i].first;

        arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());

    int result = 0;

    for(int i=0;i<n;i++){

        int x = (arr[i].second - (i+1));
        result = max(result, x);
    }

    cout << result + 1 << '\n';

    return 0;
}