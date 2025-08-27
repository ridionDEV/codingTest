#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    stack<int> st;
    vector<char> result;

    bool isTrue = true;

    int num = 1;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        if(input >= num){
            while(input >= num){
                st.push(num);
                result.push_back('+');
                num++;
            }

            st.pop();
            result.push_back('-');
        }
        else{
            int temp = st.top();
            st.pop();
            if(temp > input){
                cout << "NO" << endl;
                isTrue = false;
                break;
            }
            else{
                result.push_back('-');
            }
        }
    }

    if(isTrue){
        for(int i=0;i<result.size();i++){
            cout << result[i] << endl;
        }
    }




    return 0;
}