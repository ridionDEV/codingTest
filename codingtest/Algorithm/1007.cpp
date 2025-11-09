#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N;
double result;

bool visited[20] = {false};

void dfs(int now, int cnt){

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;


    for(int i=0;i<t;i++){

        result = 1e9+7;
        memset(visited, 0, sizeof(visited));
        vector<pair<int,int>> P;

        cin >> N;
        for(int i=0;i<N;i++){
            int a,b;
            cin >> a >> b;
            P.push_back({a,b});
        }



        dfs(0,0);
        cout << result << '\n';

    }



    return 0;
}