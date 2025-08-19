#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    int arr[100001] = {0};

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int input;
        cin >> input;
        arr[i] = arr[i-1] + input;
    }

    int x,y;

    for(int i=0;i<m;i++){
        cin >> x >> y;
        cout << arr[y] - arr[x-1] << endl;
    }




    return 0;
}