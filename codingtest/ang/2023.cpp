#include <iostream>

using namespace std;

int n;

void dfs(int num,int digit){
    if(digit == n){
        for(int i=2;i<num/2;i++){
            if(num%i==0) return;
        }

        cout << num << '\n';
        return;
    }

    int v[5] = {1,3,5,7,9};

    for(int i=0;i<5;i++){
        int next = (num*10) + v[i];
        bool isTrue = true;

        for(int j=2;j<next/2;j++){
            if(next%j==0){
                isTrue = false;
                break;
            }
        }

        if(isTrue)
            dfs(num*10 + v[i], digit+1);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    int prime[4] = {2,3,5,7};
    for(int i=0;i<4;i++){
        dfs(prime[i],1);
    }

    //2357

    
    return 0;
}