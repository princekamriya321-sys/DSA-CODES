#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
int i;
int j;
int t;
Pair(int a,int b,int c){
i = a;
j = b;
t = c;
}
};
int Rottenoranges(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<Pair> q;
    for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(mat[i][j] == 2){
      q.push(Pair(i,j,0));
}
}
}
int ans = -1;
while(q.size()>0){
    Pair rem = q.front();
    q.pop();
    int crow = rem.i;
    int ccol = rem.j;
    int ctime = rem.t;
    ans = ctime;
    if(crow-1>=0 && mat[crow-1][ccol] == 1){
        q.push(Pair(crow-1,ccol,ctime+1));
        mat[crow-1][ccol] = 2;
    }
    if(ccol+1 <m && mat[crow][ccol+1] == 1){
        q.push(Pair(crow,ccol+1,ctime+1));
        mat[crow][ccol+1] = 2;
    }
    if(crow+1 <n  && mat[crow+1][ccol] == 1){
        q.push(Pair(crow+1,ccol,ctime+1));
        mat[crow+1][ccol] = 2;
    }
    if(ccol-1 >= 0 && mat[crow][ccol-1] == 1){
        q.push(Pair(crow,ccol-1,ctime+1));
        mat[crow][ccol-1] = 2;
    }
}
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        if(mat[i][j] == 1){
            return -1;
        }
    }
}
return ans;
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>mat(n,vector<int>(m));
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>mat[i][j];
    }
}
int ans = Rottenoranges(mat);
cout<<ans<<endl;
return 0;
}
