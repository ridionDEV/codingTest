#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> A(1003002,0);
    for(int i=2;i<1003002;i++){
        A[i] = i;
    }
    for(int i=2;i<sqrt(1003002);i++){
        if(A[i]!=0){
            for(int j=i+i;j<1003002;j = j+i){
                A[j] = 0;
            }
        }
    }

    for(int i=n;i<1003002;i++){
        if(A[i]!=0){
            string temp = to_string(A[i]);
            string s = "";
            for(int j=temp.length()-1;j>=0;j--){
                s += temp[j];
            }
            if(A[i] == stoi(s)){
                cout << A[i];
                break;
            }
        }
    }
    return 0;
}