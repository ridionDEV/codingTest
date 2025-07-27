#include <iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;
        int dist = y - x;
        int count =0;
        int current = 0;
        int move = 0;
        while(true){
            move += 1;
            current += (move)*2;
            count += 2;

            if(current - move >= dist){
                cout << count-1 << '\n';
                break;
            }
            else if(current >= dist){
                cout << count << '\n';
                break;
            }
        }
    }

    return 0;
}