#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    vector<long long> arr(n);

    long long start = 0;
    long long end = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];

        start = max(start, arr[i]);
        end += arr[i];
    }

    while(start < end){
        long long mid = (start + end) / 2;
        int count = 0;
        int sum = 0;

        for(int i =0;i<n;i++){
            if(sum + arr[i] > mid){
                count ++;
                sum = 0;
            }

            sum += arr[i];
        }
        if(sum!=0){
            count ++;
        }

        if(count > m){
            start = mid + 1;
        }
        else if(count <= m){
            end = mid;
        }
    }


    cout << start;

    return 0;
}