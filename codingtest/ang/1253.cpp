#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    int cnt = 0;
    
    for(int i=0;i<n;i++){
        int x = 0;
        int y = n-1;
        long long find = A[i];

        while(x < y){
            if(x == i) x++;
            else if(y==i) y--;
            else if(A[x] + A[y] == find){
                cnt++;
                break;
            }
            else if(A[x] + A[y] > find){
                y--;
            }
            else if(A[x] + A[y] < find){
                x++;
            }
        }
    }

    cout << cnt << endl;


    return 0;
}