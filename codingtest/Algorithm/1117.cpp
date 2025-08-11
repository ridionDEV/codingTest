#include <iostream>

using namespace std;

long long w,h,f,x1,y1,x2,y2;

long long value = 0;

int c;

int main(void){

    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

    long long area = (x2-x1) * (y2-y1);
    int cnt = c +1;


    if(f <= w-f){
        if(f >= x2){
            value += (area * 2) * (cnt);
        }
        else if(f > x1){
            value += (area + (f - x1) * (y2 - y1)) * (cnt);
        }
        else if(f <= x1){
            value += area * (cnt);
        }

    }
    else{

        if(w-f <= x1){
            value += area * (cnt);

        }
        else if(w-f >= x2){
            value += area * 2 * (cnt);

        }
        else if(w-f < x2 && w-f > x1){
            value += (area + (w-f -x1) * (y2 -y1)) * (cnt);
        }

    }


    cout << (w*h) - value << endl;

    return 0;
}