#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//9876543210 최소
//876543210
//10
//0

int n;
vector<long long> A;

void func(int num, int Lastdigit){
    A.push_back(num);

    for(int i=0;i<Lastdigit;i++){
        func(num*10 + i,i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    for(int i=0;i<10;i++){
        func(i,i);
    }


    sort(A.begin(),A.end());

    if(A.size() < n){
        cout << -1;
    }
    else{
        cout << A[n-1];
    }

    return 0;
}