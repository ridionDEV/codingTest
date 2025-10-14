#include <iostream>
#include <vector>

using namespace std;

int n,k;
int up;
int down;

int cnt=1;
vector<int> a;

void Rotation(){

    if(a[down] > 1000) a[down] -= 1000;

    if(up <= 0) up = 2*n - 1;
    else up--;
    if(down <= 0) down = 2*n -1;
    else down--;
    

}

int main(){

    cin >> n >> k;
    up = 0;
    down = n-1;
    a.resize(n*2);

    for(int i=0;i<n*2;i++){
        cin >> a[i];
    }

    while(true){
        

        //1
        Rotation();

        //2
        int i = down;
        while(true){
            if(i < 0) i = 2*n - 1;

            if(a[i] > 1000 && i == down){
                a[i] -= 1000;
            }

            if(i == 2*n - 1){
                if(a[i] > 1000 && a[0] > 0 && a[0] < 1000){
                    a[i] -= 1000;
                    a[0] += 1000 - 1;

                    if(a[0] == 1000) a[0] -= 1000;

                    
                }
            }
            else{
                if(a[i] > 1000 && a[i+1] > 0 && a[i] < 1000){
                    a[i] -= 1000;
                    a[i+1] += 1000 - 1;

                    if(a[i+1] == 1000) a[i] -= 1000;
                }
            }

            if(i == up) break;
            i--;
        }

        //3
        if(a[up] > 0){
            a[up] += 1000 - 1;

            if(a[up] == 1000) a[up] -= 1000;
        }   

        //4
        
        int c=0;

        for(int i=0;i<2*n;i++){
            if(a[i] <= 0) c++;
        }
        if(k <= c) break;
        
        cnt++;
    }

    cout << cnt;
    return 0;
}