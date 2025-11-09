#include <iostream>
#include <vector>

using namespace std;



int main(){
    int n,k;
    int up;
    int down;

    int cnt=0;
    
    cin >> n >> k;
    up = 0;
    down = n-1;

    int robot = 1001;
    vector<int> a(2*n);

    for(int i=0;i<n*2;i++){
        cin >> a[i];
    }

    while(true){
        
        cnt++;
        //1
        if(up == 0) up = (2*n - 1);
        else up--;

        if(down == 0) down = (2*n -1);
        else down--;

        if(a[down] >= robot) a[down] -= robot;

        //2
        int r = down;
        while(true){
            if(r < 0) r = (2*n - 1);

            if(a[r] >= robot){
                if(r == 2*n-1 ){
                    if(a[0]  > 0 && a[0] < robot){

                        a[r] -= robot;
                        a[0] += robot;
                        a[0]--;
                    }
                }
                else{
                    if(a[r+1]  > 0 && a[r+1] < robot){
                        a[r] -= robot;
                        a[r+1] += robot;
                        a[r+1]--;
                    }
                }
            }

            if(r == up) break;
            r--;
        }
        
        if(a[down] >= robot) a[down] -= robot;

        //3
        if (a[up] < robot && a[up] > 0) {
            a[up] += robot;  
            a[up]--;   
        }

        //4
        int c=0;
        for(int x : a){

            if(x % robot == 0) c++;
        }

        
        if(c >= k) break;
        
    }

    cout << cnt;
    return 0;
}