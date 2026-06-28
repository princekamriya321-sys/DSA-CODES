#include<bits/stdc++.h>
using namespace std;
bool helper(vector<vector<int>> &graph,vector<int> &vis,int i){
    queue<int> q;
    q.push(i);
    vis[i] = 10;
    while(q.size()>0){
        int rem = q.front();
        q.pop();
        for(auto nbr: graph[rem]){
            if(vis[nbr] == -1){
                if(vis[rem] == 10){
                    vis[nbr] = 12;
                } else {
                    vis[nbr] = 10;
                }
                q.push(nbr);
            } else {
                if(vis[rem] == vis[nbr]) return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
   int n = graph.size();
   vector<int> vis(n,-1);
for(int i =0; i<n; i++){
    if(vis[i] == -1){
        bool t = helper(graph,vis,i);
        if(t == false) return false;
    }
}
return true;
}

int main()
{
    int V = 5;

    vector<vector<int>> graph(V);

    // Undirected Graph

    graph[0].push_back(3);
    graph[0].push_back(4);

    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(4);

    graph[3].push_back(0);
    graph[3].push_back(1);

    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(2);

    cout << "Adjacency List:\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for(int x : graph[i])
            cout << x << " ";

        cout << endl;
    }

    cout << endl;

    if(isBipartite(graph))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is Not Bipartite";

    return 0;
}