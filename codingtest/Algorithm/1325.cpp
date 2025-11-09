#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>> A(n+1);

    vector<pair<int,int>> result;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        A[b].push_back(a);
    }

    for(int i=1;i<=n;i++){

        queue<int> q;
        vector<bool> visited(n+1,false);

        visited[i] = true;

        int count = 1;

        for(int a : A[i]){
            if(!visited[a]){
                q.push(a);
                count++;
                visited[a] = true;
            }
        }

        while(!q.empty()){
            int now = q.front();
            q.pop();

            for(int next : A[now]){
                if(!visited[next]){
                    q.push(next);
                    count++;
                    visited[next] = true;
                }
            }
        }

        if(result.empty())
            result.push_back({i,count});
        else if(result[0].second < count){
            result.clear();
            result.push_back({i,count});
        }
        else if(result[0].second == count){
            result.push_back({i,count});
        }
            


    }

    sort(result.begin(),result.end());

    for(int i=0;i<result.size();i++){
        cout << result[i].first << ' ';
    }

    return 0;
}