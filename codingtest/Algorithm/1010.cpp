#include <iostream>

using namespace std;

int comb(int x,int y){
    int result = 1;
    for(int i=1;i<=x;i++){
        result *= y+1-i;
        result /= i;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;
        cout << comb(x,y)  << '\n';
    }



    return 0;
}