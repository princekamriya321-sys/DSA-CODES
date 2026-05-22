#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<int> graph[n];
for(int i = 0; i<m; i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
for(int i = 0; i<=n; i++){
    cout<<i<<" -> ";
    for(int x : graph[i]){
    cout<<x<<" ";
    }
    cout<<endl;
}
return 0;
}
