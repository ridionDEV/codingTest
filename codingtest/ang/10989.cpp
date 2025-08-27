#include <iostream> //계수정렬

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int count[10001] = {};

    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        count[input]++;
    }

    for(int i=1;i<=10000;i++){
        while(count[i]--){
            cout << i << '\n';
        }
    }


    return 0;
}