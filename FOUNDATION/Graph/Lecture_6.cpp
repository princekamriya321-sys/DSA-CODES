#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> Graph(int n,int m,vector<vector<int>> &edges){
vector<vector<int>> graph(n);
for(int i = 0; i<m; i++){
int u = edges[i][0];
int v = edges[i][1];
    graph[u].push_back(v);
    graph[v].push_back(u);
}
return graph;
}
void BFS(int n,int m, vector<vector<int>> &edges){
    vector<vector<int>> graph = Graph(n,m,edges);
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(0);
    vis[0] = true;
    while (q.size()>0)
    {
    int rem = q.front();
    q.pop();
    cout<<rem<<" ";
    vector<int> nbrs = graph[rem];
    for(int x : nbrs){
        if(vis[x] == false){
            q.push(x);
            vis[x] = true;
        }
    }
    }
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>edges(m,vector<int>(2));
for(int i = 0; i<m; i++){
    for(int j = 0; j<2; j++){
        cin>>edges[i][j];
    }
}
BFS(n,m,edges);
return 0;
}
