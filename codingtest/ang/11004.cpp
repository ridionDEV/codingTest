#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    vector<int> A(n,0);

    for(int i=0;i<n;i++){

        cin >> A[i];
    }

    sort(A.begin(),A.end());


    cout << A[k-1];

    return 0;
}