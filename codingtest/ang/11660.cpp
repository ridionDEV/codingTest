#include <iostream>

using namespace std;

int arr[1025][1025] = {0};

int main(void){

    int n,m;
    cin >> n >> m;

    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            int input;
            cin >> input;

            arr[y][x] = arr[y][x-1] + arr[y-1][x] - arr[y-1][x-1] + input;
        }
    }

    

    for(int i=0;i<m;i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1] + arr[y1-1][x1-1];
    }




    return 0;
}