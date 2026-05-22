#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<vector<int>>Psum2DMatrix(vector<vector<int>>&mat){
int n = mat.size();
int m = mat[0].size();
vector<vector<int>> prefixsum(n,vector<int>(m));
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        if(j == 0){
            prefixsum[i][j] = mat[i][j];
        } else {
            prefixsum[i][j] = prefixsum[i][j-1] + mat[i][j];
        }
    }
}
for(int j = 0; j<m; j++){
    for(int i = 1; i<n; i++){
        prefixsum[i][j] = prefixsum[i-1][j] + prefixsum[i][j];
    }
}
return prefixsum;
}
int SumRegion(int x1,int y1,int x2, int y2,vector<vector<int>>&mat){
vector<vector<int>> prefixsum = Psum2DMatrix(mat);
    int sum = 0;
    sum += prefixsum[x2][y2];
    if(x1 -1 >=0){
        sum = sum - prefixsum[x1-1][y2];
    }
    if(y1-1>=0){
    sum = sum - prefixsum[x2][y1-1];
    }
    if(x1-1 >=0 && y1 - 1>=0){
        sum += prefixsum[x1-1][y1-1];
    }
 return sum;
}
int main() {
int n,m;  
cin>>n>>m;
vector<vector<int>> mat(n,vector<int>(m));
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>mat[i][j];
}
}
int ans = SumRegion(2,2,4,4,mat);
cout<<ans<<endl;
return 0;
}