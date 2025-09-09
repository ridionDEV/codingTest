#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> A(n);
    vector<int> g(26,0);
    vector<int> v(26,0);

    for(int i=0;i<n;i++){
        cin >> A[i];

        for(int j=0;j<A[i].length();j++){
            g[A[i][j] - 'A'] += 1 * pow(10, (int)A[i].length() - j - 1);
        }
    }

    int num = 9;
    for(int i=0;i<10;i++){
        int temp = 0;
        int index = -1;
        for(int j=0;j<26;j++){
            if(temp < g[j]){
                temp = g[j];
                index=j;
            }
        }
        
        if(index == -1) break;

        g[index] = 0;
        v[index] = num;
        num--;
    }

    int result = 0;

    for(int i=0;i<n;i++){
        string temp = "";
        for(int j=0;j<A[i].length();j++){
            temp += to_string(v[A[i][j] - 'A']);
        }
        result += stoi(temp);
    }


    cout << result;
    return 0;
}