#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<char> Left;
    stack<char> Right;

    string input;
    cin >> input;

    int n = input.length();

    for(int i=0;i<n;i++){
        Left.push(input[i]);
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        char input;

        cin >> input;


        

        if(input == 'P'){
            char c;
            cin >> c;

            Left.push(c);

        }
        else if(input == 'L'){
            if(!Left.empty()){
                Right.push(Left.top()); Left.pop();
            }
        }
        else if(input == 'D'){
            if(!Right.empty()){
                Left.push(Right.top()); Right.pop();

            }
        }
        else if(input == 'B'){
            if(!Left.empty())
                Left.pop();
        }
    }


    while(!Left.empty()){
        Right.push(Left.top()); Left.pop();
    }

    while(!Right.empty()){
        cout << Right.top();

        Right.pop();
    }

    return 0;
}