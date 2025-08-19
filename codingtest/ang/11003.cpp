#include <iostream>
#include <deque>

using namespace std;
using Node = pair<int, long long>;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,l;
    cin >> n >> l;

    deque<Node> dq;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        while(!dq.empty() && dq.back().second > input){
            dq.pop_back();
        }

        dq.push_back(Node(i, input));

        if(dq.front().first <= i - l){
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }




    return 0;
}