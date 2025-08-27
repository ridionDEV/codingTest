#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int,int>> mystack;
    vector<int> result(n);

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        while(!mystack.empty() && mystack.top().first < input) mystack.pop();

        if(!mystack.empty()) result[i]=mystack.top().second;
        else result[i] = 0;

        mystack.push(pair(input, i + 1));
    }


    for(int value : result){
        cout << value << ' ';
    }


    return 0;
}