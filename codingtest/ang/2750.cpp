#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){

        bool b = false;

        for(int j=0;j<n-1;j++){


            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                b =true;
            }
        }

        if(!b) break;
    }

    for(int v : arr){
        cout << v << '\n';
    }



    return 0;
}