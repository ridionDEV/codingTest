#include <iostream> //기수 정렬 메모리초과
#include <cmath>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<queue<int>> q(10);

    int maxlength = 0;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        int digits = (int)log10(input) + 1;
        maxlength = max(maxlength, digits);
        q[input%10].push(input);
    }

    vector<int> A(n);
    int v = 10;

    for(int j=1;j<maxlength;j++){

        int index = 0;

        for(int i=0;i<10;i++){
            while(!q[i].empty()){

                A[index++] = q[i].front();
                q[i].pop();
            }
        }

        for(int k=0;k<n;k++){
            q[(A[k]/v)%10].push(A[k]);
        }

        v = v*10;
    }
    for(int i=0;i<10;i++){
        while(!q[i].empty()){
            cout << q[i].front() << '\n';
            q[i].pop();
        }
    }

    return 0;
}