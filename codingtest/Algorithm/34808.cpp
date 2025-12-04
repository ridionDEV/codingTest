#include <iostream>

using namespace std;

int main(){

    long long N,M,K;
    cin >> N >> M >> K;

    if(N*M >= 4){
        cout << -1;
        return 0;
    }

    long long temp = 0;

    if((N==3 || M==3) && K==0){
        cout << -1;
        return 0;
    }

    for(int i=0;i<N;i++){
        for(int j =0;j<M;j++){
            
            
            cout << temp + K << ' ';
            temp = temp+K;
        }
        cout << '\n';
    }

    return 0;
}