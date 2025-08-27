#include <iostream>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string n;
    cin >> n;

    for(int i=0;i<n.length()-1;i++){

        int mAx = 0;
        int temp = i;

        for(int j=i;j<n.length();j++){
            if(mAx < n[j] - '0'){
                mAx = n[j] - '0';
                temp = j;
            }

        }

        n[temp] = n[i];
        n[i] = mAx + '0';
    }

    for(char c : n){
        cout << c;
    }


    return 0;
}