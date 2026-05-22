#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> Graph(int n,int m,vector<vector<int>> &edges){
vector<vector<int>> graph(n);
for(int i = 0; i<m; i++){
int u = edges[i][0];
int v = edges[i][1];
    graph[u].push_back(v);
}
return graph;
}
void Topologicalsort(vector<vector<int>> &graph,int n,int m){
vector<int> indegree(n,0);
queue<int> q;
for(int i = 0; i<n; i++){
    vector<int> arr = graph[i];
    for(int v : arr){
        indegree[v]++;
    }
}
for(int i = 0; i<n; i++){
    if(indegree[i] == 0){
        q.push(i);
    }
}
while(q.size() > 0 ){
    int rem = q.front();
    q.pop();
    cout<<rem<<" ";
    vector<int> arr = graph[rem];
    for(int v: arr){
        indegree[v]--;
        if(indegree[v] == 0){
            q.push(v);
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
vector<vector<int>> graph = Graph(n,m,edges);
Topologicalsort(graph,n,m);
return 0;
}
