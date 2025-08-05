#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<pair<int,int>> comb;
int n,m;
int result=98765432;
void dfs(int start,int r){
    if(r==m){

        int value =0;

        for(int i=0;i<house.size();i++){

            int distance=98765432;

            for(int j=0;j<comb.size();j++){

                distance = min(distance, abs(house[i].first-comb[j].first)+abs(house[i].second-comb[j].second));

            }

            value += distance;
        }

        result = min(result,value);

        return;
    }

    for(int i=start;i<chicken.size();i++){

        comb.push_back(pair(chicken[i].first,chicken[i].second));

        dfs(i+1,r+1);

        comb.pop_back();
    }
}

int main(void){

    
    cin >> n >> m;

    board = vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> board[i][j];

            if(board[i][j]==1)
                house.push_back(pair(i,j));
            if(board[i][j]==2){
                chicken.push_back(pair(i,j));
            }

        }

    dfs(0,0);
    cout << result << endl;
    return 0;
}