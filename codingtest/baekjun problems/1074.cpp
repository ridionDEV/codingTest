#include <iostream>
using namespace std;


long long result = 0;


void function(long long n, long long r, long long c){
    if(n==0) return;

    long long length = 1;
    long long value = 1;
    int count = 0;
    
    for(int i=0;i<n-1;i++){
        length = length * 2;
        value = value * 4;
    }


    if(r >= length){
        r -= length;
        count += 2;
    }

    if(c >= length){
        c -= length;
        count += 1;
    }

    if(count!=0)
        result += count * value;

    function(n-1,r,c);
}


int main(void){

    long long n,r,c;

    cin >> n >> r >> c;

    function(n,r,c);

    cout << result << endl;

    return 0;
}