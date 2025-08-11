#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void){

    int n,m;
    int result =0;
    vector<int> crane;
    vector<int> weight(10050,0);

    cin >> n;

    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        crane.push_back(value);
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int value;
        cin >> value;
        weight[i] = (value);
    }

    sort(crane.begin(),crane.end(),greater<int>());
    sort(weight.begin(),weight.end(),greater<int>());

    if(crane[0] < weight[0]){
        cout << -1 << endl;
        return 0;
    }
    


    
    while(m>0){

        int a = 0;
        for(int i=0;i<n;i++){

            
            if(weight[a] == 0) break;

            if(crane[i] >= weight[a] && weight[a] != 0){
                
                weight.erase(weight.begin() + a);
                m--;
            }
            else if(weight[a] > crane[i] && weight[a] != 0){
                a++;
                i--;
            }

        }

        
        result++;  
    }

    cout << result << endl;

    return 0;
}