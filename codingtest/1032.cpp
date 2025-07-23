#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string *str = new string[n];

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        str[i] = input;
    }

    string result = str[0];

    for(int j=0;j<n;j++)
        for(int i=0;i<str[0].length();i++){
            if(j!=n-1)
                if(str[j][i]!=str[j+1][i])
                    result[i] = '?';
    }

    cout << result << endl;

    return 0;
}