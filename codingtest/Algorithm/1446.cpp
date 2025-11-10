#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    struct Struct
    {
        int start,end,length;
    };
    

    int n,d;
    cin >> n >> d;
    vector<Struct> A;

    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;

        if(b > d || (b-a)-c <= 0){
            continue;
        }

        A.push_back({a,b,c});
    }
    
    sort(A.begin(),A.end());

    int dp[d+1];

    return 0;
}