#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    vector<int> A;
    vector<int> B;
    string s ="";
    int result = 0;

    for(int i=0;i<input.length();i++){
        if(input[i]=='+'){
            A.push_back(stoi(s));
            B.push_back(1);
            s = "";
        }
        else if(input[i]=='-'){
            A.push_back(stoi(s));
            B.push_back(0);
            s = "";
        }
        else{
            s += input[i];
        }
    }

    A.push_back(stoi(s));


    result += A[0];

    for(int i=0;i<B.size();i++){
        
        if(B[i]==1){
            result += A[i+1];
        }
        else if(B[i]==0){
            int temp = A[i+1];

            if(i+1 == B.size()){
                result -= A[i+1];
                break;
            }

            while(B[i+1] != 0){

                i++;
                temp += A[i+1];

                if(i+1 >= B.size()) break;
            }

            result -= temp;
        }
    }

    cout << result;
    return 0;
}