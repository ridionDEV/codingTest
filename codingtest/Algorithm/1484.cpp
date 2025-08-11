#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    int g;
    cin >> g;

    vector<int> x;

    for(int i=1; i <= (g/i) ;i++){
        
        if(g%i == 0){
            int a = i;
            int b = g/i;

            if((b-a)%2 != 0 || a==b) continue;

            x.push_back((a+b)/2);

        }


    }

    sort(x.begin(),x.end());


        if(!x.empty()){
            for(int value : x)
                cout << value << endl;
        }
        else
            cout << -1 << endl;

    return 0;
}