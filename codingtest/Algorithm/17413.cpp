#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    getline(cin,s);

    stack<char> c;

    string result = "";

    for(int i=0;i<s.length();i++){

        if(s[i]=='<'){
            while(!c.empty()){
                result += c.top();
                c.pop();
            }

            while(s[i]!='>'){
                result += s[i];
                i++;
            }

            result += '>';
        }
        else if(s[i]==' '){
            while(!c.empty()){
                result += c.top();
                c.pop();
            }

            result += ' ';
        }
        else{
            c.push(s[i]);
        }


    }

    while(!c.empty()){
        result += c.top();
        c.pop();
    }

    cout << result << '\n';

    return 0;
}