#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> A;

void mergeSort(int start,int end){
    if(start < end){
        
        int mid = ( start + end ) / 2;

        mergeSort(start, mid);
        mergeSort(mid + 1, end);

        int x = mid-start +1;
        int y = end - mid;

        vector<int> L(x);
        vector<int> R(y);

        for(int i=0;i<x;i++) L[i] = A[start + i];
        for(int i=0;i<y;i++) R[i] = A[mid + 1 + i];

        int i=0,j=0,k=start;
        while(i < x && j < y){
            if(L[i] <= R[j]) A[k++] = L[i++];
            else A[k++] = R[j++];
        }

        while(i < x) A[k++] = L[i++];
        while(j < y) A[k++] = R[j++];
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    A.resize(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    mergeSort(0,n-1);

    for(int x : A){
        cout << x << '\n';
    }
    return 0;
}