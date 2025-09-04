#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n,k,result;
    cin >> n >> k;

    long long start = 1;
    long long end = k;

    while(start < end){
        long long mid = (start+end) / 2;
        long long count = 0;

        for(int i=1;i<=n;i++){
            count += min(mid/i,n);
        }

        if(count < k){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }





    cout << start;
    return 0;
}