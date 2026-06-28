#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> rankpar;
int find(int x){
    if(x == par[x]){
        return x;
    }
    int temp = find(par[x]);
    par[x] = temp;
    return temp;
}
void unionfunc(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    if(rankpar[px] > rankpar[py]){
        par[py] = px;
    } else if(rankpar[py] > rankpar[px]){
        par[px] = py;
    } else {
        par[py] = px;
        rankpar[px]++;
    }
}
int minmalwarespred(vector<vector<int>> &edges, int n,vector<int> &initial)
{
   par.resize(n);
   rankpar.resize(n);
for(int i =0; i<n; i++){
    par[i] = i;
    rankpar[i] = 1;
}
for(int i =0; i<n; i++){
    int x = edges[i][0];
    int y = edges[i][1];
    unionfunc(x,y);
}
vector<int> leadersize(n,0);
for(int i =0; i<n; i++){
    leadersize[find(i)]++;
}
vector<int> infcount(n,0);
for(int i = 0; i<initial.size(); i++){
    infcount[find(initial[i])]++;
}
sort(initial.begin(),initial.end());
int ansidx = -1;
int anscount = INT_MIN;
for(int i =0; i<initial.size(); i++){
    int infnode = initial[i];
    int linfnode = find(infnode);
    if(infcount[linfnode] == 1 && leadersize[linfnode] > anscount){
anscount = leadersize[linfnode];
ansidx = infnode;
    }
}
return ansidx;
}

int main()
{
    int n = 11;

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,0},

        {4,5},
        {5,6},
        {6,4},

        {7,8},
        {8,9},
        {9,10},
        {10,7}
    };
    int m = 4;
    vector<int> initial(4);
    initial[0] = 0;
    initial[1] = 4;
    initial[2] = 6;
    initial[3] = 7;
int ans = minmalwarespred(edges,n,initial);
cout<<ans<<endl;
    return 0;
}