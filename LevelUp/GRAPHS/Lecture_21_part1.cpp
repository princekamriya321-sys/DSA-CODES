#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> rankpar;
int cnt = 0;
int find(int x){
    if(x == par[x]) return x;
    int temp = find(par[x]);
   par[x] = temp;
   return temp;
}
void unionfunc(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    if(rankpar[px] > rankpar[py]) {
    par[py] = px;
    } else if(rankpar[py] > rankpar[px]){
        par[px] = py;
    } else {
        par[px] = py;
        rankpar[py]++;
    }
    cnt--;
}
vector<int> numIslands2(int n, int m, vector<vector<int>> &positions)
{
vector<int> ans;
par.assign(n*m,-1);
rankpar.resize(n*m);
for(int i =0; i<positions.size(); i++){
    int row = positions[i][0];
    int col = positions[i][1];
    int cellno = row*m + col;
if(par[cellno] != -1){
    ans.push_back(cnt);
    continue;
}
par[cellno]= cellno;
rankpar[cellno] = 1;
cnt++;
vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
for(int j = 0; j<4; j++){
    int rowdash = row + dir[j][0];
    int coldash = col + dir[j][1];
    int celldash = rowdash*m + coldash;
    if(rowdash < 0 || coldash< 0 || rowdash >= n || coldash >= m) continue;
    if(par[celldash] == -1) continue;
    unionfunc(cellno,celldash);
}
ans.push_back(cnt);
}
return ans;
}

int main()
{
    int n = 3;
    int m = 5;

    vector<vector<int>> positions = {
        {0,3},
        {1,2},
        {0,2},
        {1,4},
        {2,3},
        {1,3}
    };

    cout << "Grid Size : " << m << " x " << n << endl;

    cout << "\nPositions:\n";

    for(auto &p : positions)
    {
        cout << "(" << p[0] << ", " << p[1] << ")" << endl;
    }

    cout << endl;

    vector<int> ans = numIslands2(n, m, positions);

    cout << "Number of Islands after each operation:\n";

    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}