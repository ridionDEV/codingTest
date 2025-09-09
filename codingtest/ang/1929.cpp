#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m,n;
    cin >> m >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]= i+1;
    }

    a[0] = 0;

    for(int i=0;i<sqrt(n);i++){
        if(a[i]!=0){
            for(int j=i+1;j<n;j++){
                if(a[j]%(i+1)==0){
                    a[j] = 0;
                }
            }
        }
    }

    for(int i=m-1; i<n ; i++){
        if(a[i]!=0)
            cout << a[i] << '\n';
    }


    return 0;
}