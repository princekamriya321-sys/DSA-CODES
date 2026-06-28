#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &graph)
{
    // Write Floyd-Warshall Algorithm here.
    int n = graph.size();
 for(int k = 0; k<n-1; k++){
    for(int u = 0; u<n; u++){
        for(int v = 0; v<n; v++){
            if(graph[u][k] != INT_MAX && graph[k][v] != INT_MAX){
                graph[u][v] = min(graph[u][v],graph[u][k] + graph[k][v]);
            }
        }
    }
 }


}

int main()
{
    int V = 4;
    const int INF = 1e9;

    vector<vector<int>> graph(V + 1, vector<int>(V + 1, INF));

    // Distance from a vertex to itself is 0
    for(int i = 1; i <= V; i++)
        graph[i][i] = 0;

    // Edges
    graph[1][2] = 3;
    graph[2][1] = 8;
    graph[2][3] = 2;
    graph[3][4] = 1;
    graph[4][1] = 2;
    graph[1][4] = 7;
    graph[3][1] = 5;

    cout << "Adjacency Matrix:\n";

    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            if(graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    floydWarshall(graph);
  for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            if(graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}