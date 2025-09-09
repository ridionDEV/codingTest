#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int l,c;
    cin >> l >> c;
    vector<char> A(c);
    for(int i=0;i<c;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    for(int i=0;i<c;i++){
        if(c-i < l) break;

        string temp = "";
        temp += A[i];

        for(int j=0;j<l-1;j++){
            
        }
    }


    return 0;
}