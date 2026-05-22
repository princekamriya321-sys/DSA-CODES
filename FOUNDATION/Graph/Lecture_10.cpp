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
void DFS(vector<vector<int>> &graph,vector<bool> vis,int src){
   vector<int> nbrs = graph[src];
   for(int v: nbrs){
    if(vis[v] == false){
        vis[v] = true;
        DFS(graph,vis,v);
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
vector<vector<int>> graph = Graph(n,m,edges);
vector<bool> vis(n,false);
DFS(graph,vis,0);
return 0;
}
