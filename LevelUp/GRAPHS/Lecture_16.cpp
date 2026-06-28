#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph,vector<bool> &vis,stack<int> &st,int src){
    vis[src] = true;
    for(auto& v: graph[src]){
        if(vis[v] == false){
            dfs(graph,vis,st,v);
        }
    }
    st.push(src);
}
int Kosaraju(vector<vector<int>> &graph,int v){
    vector<bool> vis(v,false);
    stack<int> st;
    for(int i =0; i<v; i++){
        if(vis[i] == false){
            dfs(graph,vis,st,i);
        }
    }
int mother_vtx = st.top();
fill(vis.begin(),vis.end(),false);
stack<int> st2;
dfs(graph,vis,st2,mother_vtx);
for(int i =0; i<vis.size(); i++){
    if(vis[i] == false) return -1;
}
return mother_vtx;
}
int main(){

    int V = 8;
    vector<vector<int>> graph(V);
     graph[7].push_back(1);
     graph[7].push_back(0);
     graph[7].push_back(3);
     graph[7].push_back(6);
     graph[7].push_back(5);
     graph[5].push_back(6);
     graph[3].push_back(4);
     graph[2].push_back(3);
     graph[1].push_back(2);
     int ans = Kosaraju(graph,V);
     cout<<ans<<endl;
}