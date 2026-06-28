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
vector<int> redundantconnection(vector<vector<int>> &edges, int n)
{
   par.resize(n+1);
   parrank.resize(n+1);
for(int i =1; i<=n; i++){
    par[i] = i;
    parrank[i] = 1;
}
for(int i =0; i<edges.size(); i++){
    int u = edges[i][0];
    int v= edges[i][1];
   bool flag = unionfunc(u,v);
   if(flag == false){
    return {u,v};
   }
}
    return {0,0};
}

int main()
{
    int n = 7;
vector<vector<int>> edges = {

    {1,2},
    {1,5},
    {2,3},
    {2,7},
    {7,3},
    {5,4},
    {5,6}

};

vector<int> ans = redundantconnection(edges,n);
cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}