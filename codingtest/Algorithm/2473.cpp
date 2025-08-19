#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }


    

    sort(A.begin(),A.end());


    vector<long long> result(3,0);

    long long mini = LLONG_MAX;

    for(int i=0;i<=n-3;i++){
        int x = i+1;
        int y = n-1;

        while(y > x){

            if(mini> abs(A[i] + A[x] + A[y])){
                mini = abs(A[i] + A[x] + A[y]);
                

                result[0] = A[i];
                result[1] = A[x];
                result[2] = A[y];

                if(mini == 0) break;
            }


            if(A[i] + A[x] + A[y] > 0){
                y--;
            }
            else{
                x++;
            }
        }
    }

    for(int i=0;i<3;i++){
        cout << result[i] << " ";
    }

    return 0;

}