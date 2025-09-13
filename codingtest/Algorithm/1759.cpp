#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l,c;
vector<char> A;
vector<char> result;
string vowels = "aeiou";

bool isVowel(char c){
    return vowels.find(c) != string::npos;
}
void dfs(int now,int depth,int vowelCnt, int consonantCnt){
    if(depth == l){
        if(vowelCnt>=1 && consonantCnt >= 2){
            for(char c : result) cout << c;
            cout << '\n';
        }
        return;
    }

    if(now >= c) return;

    result.push_back(A[now]);
    if(isVowel(A[now])){
        dfs(now+1,depth+1,vowelCnt+1,consonantCnt);
    }
    else{
        dfs(now+1,depth+1,vowelCnt,consonantCnt + 1);
    }
    result.pop_back();
    dfs(now+1,depth,vowelCnt,consonantCnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> l >> c;
    A.resize(c);
    for(int i=0;i<c;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    dfs(0,0,0,0);

    return 0;
}