#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>> &edges, int src, int V)
{
 vector<int> ans(V,INT_MAX);
ans[src] = 0;
for(int i =0; i<V-1; i++){
    for(int j =0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(ans[u] != INT_MAX && ans[u]+ wt < ans[v]){
                ans[v] = ans[u] + wt;
            }
    }
}
return ans;
}

int main()
{
    int V = 6;
    int src = 0;

vector<vector<int>> edges = {
    {0,1,12},
    {0,3,7},
    {1,2,3},
    {2,3,-9},
    {2,5,5},
    {3,4,2},
    {4,5,-1}
};
    cout << "Edges:\n";
    cout << "U  V  WT\n";

    for(auto &edge : edges)
    {
        cout << edge[0] << "  "
             << edge[1] << "  "
             << edge[2] << endl;
    }

    cout << "\nSource Vertex = " << src << endl << endl;

    vector<int> ans = bellmanFord(edges, src, V);

    cout << "Shortest Distance from Source:\n";

    for(int i = 0; i < V; i++)
    {
        if(ans[i] == INT_MAX)
            cout << i << " -> INF\n";
        else
            cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}