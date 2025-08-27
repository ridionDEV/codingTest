#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n);
    stack<pair<int,int>> st;

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    st.push({A[0],1});

    long long result = 0;

    for(int i=1;i<n;i++){

        int cnt=1;

        while(!st.empty() && A[i] >= st.top().first){

            result+= st.top().second;

            if(A[i] == st.top().first){
                cnt+= st.top().second;
            }

            st.pop();
        }

        if(!st.empty()){
            result++;
        }


        st.push({A[i],cnt});
    }

    cout << result << '\n';


    return 0;
}