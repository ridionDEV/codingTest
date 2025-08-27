#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare{
    bool operator()(int a,int b){
        int a_abs = abs(a);
        int b_abs = abs(b);

        if(a_abs == b_abs) return a > b;
        else{
            return a_abs > b_abs;
        }
    }
};

int main(){

    int n;
    cin >> n;
    priority_queue<int, vector<int>, compare> pq;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        if(input == 0){
            if(pq.empty()){
                cout << 0 << endl;
            }
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else{
            pq.push(input);
        }

    }

    return 0;

}