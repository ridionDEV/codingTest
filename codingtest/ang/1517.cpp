#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> A;
vector<long long> tmp;
long long result = 0;

void mergeSort(int left, int right){

    if(left < right){

        int mid = (left + right) / 2;
        
        mergeSort(left,mid);
        mergeSort(mid + 1, right);

        for(int i=left;i<=right;i++){
            tmp[i] = A[i];
        }

        int k = left;
        int index1 = left;
        int index2 = mid + 1;

        while(index1 <= mid && index2 <= right){
            if(tmp[index1] > tmp[index2]){
                A[k++] = tmp[index2++];
                result += mid - index1 + 1;
            }
            else{
                A[k++] = tmp[index1++];
            }
        }

        while(index1 <= mid) A[k++] = tmp[index1++];
        while(index2 <= right) A[k++] = tmp[index2++];

    }

}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    A.resize(n);
    tmp.resize(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    mergeSort(0,n-1);



    cout << result;




    return 0;
}