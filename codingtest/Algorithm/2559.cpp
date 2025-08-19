#include <iostream>

using namespace std;


int main(){

    int n,k;
    cin >> n >> k;

    int A[100000] = {};

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    

    int sum = 0;

    for(int i=0;i<k;i++){
        sum += A[i];
    }

    int x=0;
    int y=k-1;

    int result;
    
    while(y < n){

        if(sum > result){
            result = sum;
        }

        sum -= A[x];

        x++;y++;

        sum += A[y];

        
    }

    cout << result << endl;

    return 0;
}