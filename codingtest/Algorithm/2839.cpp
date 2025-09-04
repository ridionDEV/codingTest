#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin >> n;
    int now = n;

    int sugar[] = {5,3};
    int count = 0;

    int temp = -1;
    int tempCnt;

    for(int s : sugar){
        while(s <= now){
            if(now%3==0){
                temp = now;
                tempCnt = count;
            }

            now -= s;
            count++;
        }
    }

    if(now > 0){
        if(temp > 0){
            tempCnt += temp/3;
            cout << tempCnt;
        }
        else
            cout << -1;
    }
    else{
        cout << count;
    }

    return 0;
}