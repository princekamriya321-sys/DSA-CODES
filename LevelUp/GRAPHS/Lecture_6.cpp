#include<bits/stdc++.h>
using namespace std;
vector<int> par;
int find(int x){
    if(x == par[x]){
        return x;
    }
    int temp = find(par[x]);
    return temp;
}
void unionfunc(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    par[px] = py;
}
int connectedComponents(vector<vector<int>> &edges, int n)
{
   par.resize(n);
for(int i =0; i<n; i++){
    par[i] = i;
}
for(int i =0; i<edges.size(); i++){
    int x = edges[i][0];
    int y = edges[i][1];
    unionfunc(x,y);
}
    int ans =0;
    for(int i =0; i<n; i++){
        if(par[i] == i){
            ans++;
        } 
    }
    return ans;
}

int main()
{
    int n = 7;

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,0},

        {4,5},
        {5,6},
        {6,4}
    };

    cout << "Edges:\n";
    cout << "U  V\n";

    for(auto &edge : edges)
    {
        cout << edge[0] << "  " << edge[1] << endl;
    }

    cout << "\nNumber of Connected Components = "
         << connectedComponents(edges, n);

    return 0;
}