#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,root,delNode,leafNode;

vector<int> tree[50];
bool visited[50] = {false};

void dfs(int node){
    if(node==delNode) return;
    visited[node] = true;
    
    bool isLeaf = true;


}

int main(void){
    cin >> n;

    for(int i=0;i<n;i++){
        int parent;
        cin >> parent;

        if(parent==-1) root = i;
        else tree[parent].push_back(i);
        
    }

    cin >> delNode;

    if(delNode==root){
        cout << 0 << endl;
    }
    else{
        dfs(root);
        cout << leafNode << endl;
    }
    return 0;
}