#include <iostream>

using namespace std;

long long w,h,f,x1,y1,x2,y2;

long long value = 0;

int c;

int main(void){

    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;


    if(f <= w-f){

        for(int i=0;i<c+1;i++){
            value += (x2-x1) * (y2-y1) + (f - x1) * (h/(c+1) - y1);

        }
    }
    else{

        if(w >= f + x2){
            for(int i=0;i<c+1;i++)
                value += (x2-x1) * (y2-y1) + (f - x1) * (h/(c+1) - y1);

        }
        else{
            for(int i=0;i<c+1;i++)
                value += (x2 - x1) * (y2-y1);

        }

    }


    cout << (w*h) - value << endl;

    return 0;
}