#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long n,k;
typedef pair<long long,long long> info;
vector<info> jewel;

vector<long long> bag;


int main(void){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    jewel.reserve(n);
    bag.reserve(k);

    for(int i=0;i<n;i++){
        long long x,y;
        cin >> x >> y;

        jewel.emplace_back(x,y);
    }


    for(int i=0;i<k;i++){
        long long input;
        cin >> input;

        bag.push_back(input);
    }

    sort(bag.begin(),bag.end());
    sort(jewel.begin(),jewel.end());



    
    long long result = 0;
    long long idx =0;
    priority_queue<long long> pq;

    for(long long b : bag){

        while(idx < jewel.size() && jewel[idx].first <= b){
            pq.push(jewel[idx].second);
            idx++;
        }

        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << endl;

    return 0;
}