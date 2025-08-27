#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n);
    stack<int> mystack;

    vector<int> result(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    mystack.push(0);

    for(int i=1;i<n;i++){
        while(!mystack.empty() && A[i] > A[mystack.top()]){
            result[mystack.top()] = A[i];

            mystack.pop();
        }

        mystack.push(i);
    }

    while(!mystack.empty()){
        result[mystack.top()] = -1;
        mystack.pop();
    }




    for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }

    return 0;

}