#include<bits/stdc++.h>
using namespace std;
vector<int> disc;
vector<int> low;
vector<bool> vis;
int timer = 0;
void articulationpoint(vector<vector<int>> &graph,int V,int src,int par)
{
vis[src] = true;
low[src] = timer;
disc[src] = timer;
timer++;
int child = 0;

for(auto nbr : graph[src]){

    if(nbr == par)
        continue;

    if(!vis[nbr]){

        child++;

        articulationpoint(graph,V,nbr,src);

        low[src] = min(low[src], low[nbr]);

        if(par != -1 && low[nbr] >= disc[src])
            cout << src << endl;

    }
    else{

        low[src] = min(low[src], disc[nbr]);

    }
}

if(par == -1 && child > 1)
    cout << src << endl;
}
int main()
{
    int V = 8;

    vector<vector<int>> graph(V);

    // First cycle
    graph[0].push_back(1);
    graph[0].push_back(3);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(4);

    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(0);
    graph[3].push_back(2);

    // Bridge
    graph[4].push_back(1);
    graph[4].push_back(5);
    // Second cycle
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[5].push_back(7);

    graph[6].push_back(5);
    graph[6].push_back(7);

    graph[7].push_back(5);
    graph[7].push_back(6);

    disc.resize(V);
low.resize(V);
vis.assign(V,false);
    articulationpoint(graph,V,0,-1);

    return 0;
}