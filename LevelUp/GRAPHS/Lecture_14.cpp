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

    vector<vector<int>> transpose(v);

for(int u = 0; u < v; u++){

    for(int x : graph[u]){

        transpose[x].push_back(u);

    }
}
fill(vis.begin(),vis.end(),false);
stack<int> st2;
int ans = 0;
while(st.size() > 0){
    int rem = st.top();
    st.pop();
    if(vis[rem] == false){
        dfs(transpose,vis,st2,rem);
        ans++;
    }
}
return ans;
}
int main(){

    int V = 8;
    vector<vector<int>> graph(V);
     graph[0].push_back(1);
     graph[1].push_back(2);
     graph[2].push_back(3);
     graph[2].push_back(4);
     graph[3].push_back(0);
     graph[4].push_back(5);
     graph[5].push_back(6);
     graph[6].push_back(7);
     graph[7].push_back(4);
     int ans = Kosaraju(graph,V);
     cout<<ans<<endl;
}