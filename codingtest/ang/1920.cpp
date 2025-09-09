#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    cin >> m;

    for(int i=0;i<m;i++){
        int input;
        cin >> input;

        int start = 0;
        int end = n-1;
        bool Find = false;

        while(start <= end){
            int mid = (start+end)/2;
            if(arr[mid] < input){
                start = mid + 1;
            }
            else if(arr[mid] > input){
                end = mid - 1;
            }
            else if(arr[mid] == input){
                Find = true;
                break;
            }
        }

        if(Find) cout << 1 << '\n';
        else cout << 0 << '\n';
    }


    return 0;
}