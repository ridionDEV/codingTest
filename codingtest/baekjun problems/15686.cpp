#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> comb;
int n,m;
vector<vector<int>> board;
vector<pair<int,int>> house, chicken;
int result=98765432;


void dfs(int start, int r){
    if(r==m){
        int ret=0;
        for(auto h : house){
            int dist = 98765432;
            for(auto c : comb){
                dist = min(dist, abs(h.first-c.first) + abs(h.second-c.second));
            }

            ret += dist;
        }
        result = min(result,ret);
        return;
    }

    for(int i=start;i<chicken.size();i++){
        comb.push_back(pair(chicken[i].first, chicken[i].second));
        dfs(i+1,r+1);
        comb.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    cin >> n >> m;
    board = vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cin >> board[i][j];

            if(board[i][j]==1){
                house.push_back(pair(i,j));
            }
            if(board[i][j]==2){
                chicken.push_back(pair(i,j));
            }
        }
    }

    dfs(0,0);
    cout << result << '\n';

    return 0;
}