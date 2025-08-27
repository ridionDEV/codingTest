#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int result =0 ;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int t = 0;

    for(int v : a){
        result += t + v;
        t += v;
    }

    cout << result;

    return 0;
}