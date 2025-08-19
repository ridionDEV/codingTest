#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int cnt = 1;
    int sum = 1;

    int start = 1;
    int end = 1;

    while(start != n/2 + 1){

        if(sum > n){
            sum -= start;
            start ++;
        }
        else if(sum < n){
            end++;
            sum += end;
        }
        else if(sum == n){
            cnt++;
            end ++;
            sum += end;
        }
    }

    cout << cnt << endl;

    return 0;
}