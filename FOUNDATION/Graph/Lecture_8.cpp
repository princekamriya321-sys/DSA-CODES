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
bool BFS(int n,int m, vector<vector<int>> &edges,int SN,int DN){
    vector<vector<int>> graph = Graph(n,m,edges);
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(SN);
    vis[SN] = true;
    while (q.size()>0)
    {
    int rem = q.front();
    q.pop();
    vector<int> nbrs = graph[rem];
    for(int x : nbrs){
        if(vis[x] == false){
            q.push(x);
            vis[x] = true;
        }
    }
    }
    return vis[DN];
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
bool ans = BFS(n,m,edges,0,2);
cout<<ans<<endl;
return 0;
}
