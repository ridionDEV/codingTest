#include <iostream>

using namespace std;

void func1(char c, int v);
string s;
int now[4] = {0};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,p;
    cin >> n >> p;

    
    cin >> s;

    int min[4] = {0};

    for(int i=0;i<4;i++){
        cin >> min[i];
    }

    int x = 0;
    int y = p-1;

    
    int cnt = 0;

    for(int i=0;i<p;i++){
        func1(s[i],1);
    }
    

    while(y < p){

        if(now[0] >= min[0])
            if(now[1] >= min[1])
                if(now[2] >= min[2])
                    if(now[3] >= min[3])
                        cnt++;


        func1(s[x],-1);

        x++; y++;

        func1(s[y],1);
    }


    cout << cnt << endl;

    return 0;
}

void func1(char c, int v){
    switch (c){
            case 'A':
                now[0]+= v;
                break;
            case 'C':
                now[1]+= v;
                break;

            case 'G':
                now[2]+= v;
                break;

            case 'T':
                now[3]+= v;
                break;
            default:
                break;
        }
}