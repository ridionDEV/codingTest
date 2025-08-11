#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void){

    int a[4][2] = {{2,3},{3,5},{4,2},{5,4}}; //a,f 면
    int b[4][2] = {{1,3},{3,6},{4,1},{6,4}}; //b, e 면
    int c[4][2] = {{1,2},{2,6},{5,1},{6,5}}; //c, d 면

    long long n;
    long long dice[7] = {0};
    long long minNum = 51;
    long long count =0;
    long long inside=0;;
    long long outside;
    long long maxNum = -1;


    long long min_3 = 151;
    long long min_2 = 51;

    cin >> n;

    for(int i=1;i<=6;i++){
        cin >> dice[i];
        if(minNum > dice[i]){
            minNum = dice[i];
        }

        maxNum = max(maxNum, dice[i]);
    }

    for(int i=1;i<=6;i++){
        if(i==1 || i==6){
            for(int j=1;j<=4;j++){
                min_3 = min(min_3, dice[i] + dice[a[j-1][0]] + dice[a[j-1][1]]);
                min_2 = min(min_2,dice[i] + dice[a[j-1][0]]);
            }
        }

        if(i==2 || i==5){
            for(int j=1;j<=4;j++){
                min_3 = min(min_3, dice[i] + dice[b[j-1][0]] + dice[b[j-1][1]]);
                min_2 = min(min_2,dice[i] + dice[b[j-1][0]]);
            }
        }

        if(i==3 || i==4){
            for(int j=1;j<=4;j++){
                min_3 = min(min_3, dice[i] + dice[c[j-1][0]] + dice[c[j-1][1]]);
                min_2 = min(min_2,dice[i] + dice[c[j-1][0]]);
            }
        }
    }
        

    if(n==1){ // n : 1,2 인경우
        for(int i=1;i<=6;i++)
            count += dice[i];

        count -= maxNum;
    }

    if(n>=2){ //n : 3 이상인경우
        inside = (n-2)*(n-2)*5 + (n-2)*4;
        outside = n*8 - 12;
        count += inside*minNum;


        count += min_3 * 4;
        count += min_2 * outside;

    }

    cout << count << endl;
    
    return 0;
}