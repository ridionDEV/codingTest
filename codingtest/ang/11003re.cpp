#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n,l;
    cin >> n >> l;
    deque<pair<int, long long>> dq;

    for(int i=0;i<n;i++){
        long long input;
        cin >> input;

        while(!dq.empty() && dq.back().second > input){
            dq.pop_back();
        }


        dq.push_back(pair(i,input));

        if(dq.front().first <= i-l ){
            dq.pop_front();
        }


        cout << dq.front().second << " ";
    }






    return 0;
}