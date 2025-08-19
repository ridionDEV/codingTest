#include <iostream>
#include <queue>

using namespace std;

int main(){

    float n;
    cin >> n;

    priority_queue<float> pq;

    for(int i=0;i<n;i++){
        float score;
        cin >> score;
        pq.push(score);
    }

    float high = pq.top(); pq.pop();
    float result = 100;

    while(!pq.empty()){
        result += (pq.top() / high) * 100;
        pq.pop();
    }

    cout << result / n << endl;

    return 0;
}