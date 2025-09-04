#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A;
    vector<int> B;

    int zero = 0;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        if(input < 0){
            B.push_back(input);
        }
        else if(input > 0){
            A.push_back(input);
        }
        else{
            zero ++;
        }
    }
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end());


    int result = 0;

    for(int i=0;i<A.size();i++){

        
        if(i==A.size()-1){
            result += A[i];
            break;
        }

        if(A[i]*A[i+1] > A[i] + A[i+1]){
            result += A[i] * A[i+1];
            i++;
        }
        else{
            result += A[i];
        }
    }

    for(int i=0;i<B.size();i++){

        if(i==B.size()-1){
            if(zero == 0){
                result+=B[i];
            }
            break;
        }

        result += B[i] * B[i+1];
        i++;
    }


    cout << result;
    return 0;
}