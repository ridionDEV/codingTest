#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> A(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1;i<=n;i++){
        int input;
        cin >> input;

        pq.push(input);
    }

    int result = 0;

    while(pq.size() > 1){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        result += (x+y);

        pq.push(x+y);
    }

    cout << result << endl;

    return 0;
}