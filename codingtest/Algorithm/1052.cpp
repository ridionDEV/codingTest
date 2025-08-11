#include <iostream>
#include <queue>

using namespace std;

long long k;
long long n;
long long result = 0;
long long cnt = 0;

queue<long long> q;

void function(long long bottle, long long value){

    if(k >= (bottle + cnt) ){
        return;
    }

    if(bottle != 1){
        if(bottle%2==1){
            q.push(value);
            cnt++;
        }

        function(bottle/2, value*2);
    }
    else{
        while(!q.empty()){
            long long x = q.front(); q.pop();
            if(!q.empty()){
                long long y = q.front();
                result += (y-x);
                q.front() = q.front() * 2;
                cnt--;
            }
            else{ //남는 요소 하나밖에 없을때

                result += value - x;
                cnt--;
            }


            if(k >= bottle + cnt){
                return;
            }
        }
    }
}

int main(void){

    cin >> n >> k;

    function(n,1);

    cout << result << endl;
    return 0;
}