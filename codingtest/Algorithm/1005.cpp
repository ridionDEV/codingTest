#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test,n;

    cin >> test;
    for(int i=0;i<test;i++){
        int n,k,w;
        cin >> n >> k;
        vector<vector<int>> node(n+1,vector<int>());
        vector<int> dp(n+1);
        vector<int> t(n+1);
        vector<int> indegree(n+1,0);

        for(int j=1;j<=n;j++){
            cin >> t[j];
        }
        for(int b=0;b<k;b++){
            int x,y;
            cin >> x >> y;
            node[x].push_back(y);
            indegree[y]++;
        }

        cin >> w;

        queue<int> q;

        for(int a=1;a<=n;a++){
            if(indegree[a] == 0){
                q.push(a);
                dp[a] = max(dp[a], t[a]);
            }
        }
        

        while(!q.empty()){
            int now = q.front(); q.pop();

            for(int next : node[now]){
                dp[next] = max(dp[next], dp[now] + t[next]);
                
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }

        }

        cout << dp[w] << '\n';
    }
    return 0;
}