#include <iostream>

using namespace std;

int main(){

    long long x,y;
    cin >> x >> y;


    long long z = (y*100)/x;

    //cout << z;
    if(z == 100 || z==99){
        cout << -1;
        return 0;
    }
    
    long long start = 1;
    long long end = 1000000000;

    long long mid;

    while(true){
        mid = (start+end) / 2;
        //start = start / 2;

        if(start == end) break;

        long long temp = ((y+mid)*100) / (x+mid);

        if(temp >= z+1){
            end = mid;

        }
        else{
            start = mid+1;
        }
   }

    cout << mid;

    return 0;
}