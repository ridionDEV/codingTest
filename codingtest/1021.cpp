#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> queue(n);
    for(int i=0;i<n;i++){
        queue[i] = 0;
    }

    for(int i=0;i<m;i++){
        int r;
        cin >> r;
        queue[r-1] = i+1;
    }

    int count =0;

    for(int i=1;i<m+1;i++){
        for(int j=0;j<n;j++){
            if(queue[j]==i)
                if(j==0){
                    queue.erase(queue.begin());
                    n--;
                    break;
                }
                else{
                    int k;
                    k = min(j, n-j);
                    count += k;
                    if(k==j)
                        rotate(queue.begin(),queue.begin()+k,queue.end());
                    else
                        rotate(queue.begin(),queue.end()-k,queue.end());

                    queue.erase(queue.begin());
                    n--;
                    break;
                }
        }
        
    }

    cout << count << endl;
    return 0;
}