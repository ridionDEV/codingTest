#include <iostream>
#include <cmath>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;

        int dist = y-x;
        int d = sqrt(dist);
        if(d*d ==dist)
            cout << 2*d - 1 << endl;
        else if(d*(d+1) >= dist)
            cout << 2*d << endl;
        else if(d*d < dist)
            cout << 2*d + 1 << endl;
        
    }

    return 0;
}