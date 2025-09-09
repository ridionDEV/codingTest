#include <iostream>
#include <cmath>
using namespace std;
long arr[10000001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long a,b;
    cin >> a >> b;

    for(int i=2;i<10000001;i++){
        arr[i] = i;
    }

    for(int i=2;i<=sqrt(10000001);i++){
        if(arr[i]==0) continue;

        for(int j =i+i; j<10000001;j = j + i){
            arr[j] = 0;
        }
    }

    int count = 0;

    for(int i=2;i<10000001;i++){
        if(arr[i] != 0){
            long temp = arr[i];

            while((double)arr[i] <= (double)b / (double)temp){
                if((double)arr[i] >= (double)a / (double)temp)
                    count++;
                temp = temp * arr[i];
            }
        }
    }

    cout << count;

    return 0;
}