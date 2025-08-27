#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> bpq;
    priority_queue<int> apq;

    for(int i=0;i<n;i++){ //100000
        int input;
        cin >> input;
        if(i==0){
            apq.push(input);
            cout << apq.top() << '\n';
            continue;
        }

        if(input < apq.top()){
            apq.push(input);

        }
        else{
            bpq.push(input);
        }

        if(apq.size() < bpq.size()){
            apq.push(bpq.top());
            bpq.pop();
        }
        else if(apq.size() - bpq.size() == 2){
            bpq.push(apq.top());
            apq.pop();
        }


        cout << apq.top() << '\n';
    }



    return 0;
}