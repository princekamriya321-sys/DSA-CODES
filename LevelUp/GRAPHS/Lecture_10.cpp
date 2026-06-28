#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> parrank;
int find(int x){
    if(x == par[x]){
        return x;
    }
    int temp = find(par[x]);
    par[x] = temp;
    return temp;
}
bool unionfunc(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return false;
   if(parrank[px] > parrank[py]){
    par[py] = px;
   } else if(parrank[py] > parrank[px]){
    par[px] = py;
   } else {
    par[py] = px;
    parrank[px]++;
   }
   return true;
}
int Krushkals(vector<vector<int>> &edges, int n)
{
   par.resize(n);
   parrank.resize(n);
for(int i =0; i<n; i++){
    par[i] = i;
    parrank[i] = 1;
}
int ans =0;
sort(edges.begin(), edges.end(),[](auto &a,auto &b){
return a[2] <b[2];
});
for(int i =0; i<edges.size(); i++){
    int u = edges[i][0];
    int v= edges[i][1];
    int wt = edges[i][2];
   bool flag = unionfunc(u,v);
   if(flag == true){
    ans+= wt;
   }
}
    return ans;
}

int main()
{
    int n = 7;

    vector<vector<int>> edges = {
        {0,1,16},
        {1,2,14},
        {2,3,12},
        {0,3,10},
    };


    cout << "Minimum Spanning Tree = "
         << Krushkals(edges, n);

    return 0;
}