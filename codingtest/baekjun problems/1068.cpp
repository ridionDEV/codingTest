#include <iostream>
#include <vector>

using namespace std;

int n,root,delNode, Count = 0;

vector<int> tree[50];
bool visited[50] = {false};

void dfs(int node){
    if(node==delNode) return;
    visited[node] = true;
    
    bool isLeaf = true;
    for(int child : tree[node]){
        if(child != delNode){
            isLeaf = false;
            dfs(child);
        }
    }
    if(isLeaf) Count++;
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
        cout << Count << endl;
    }
    return 0;
}