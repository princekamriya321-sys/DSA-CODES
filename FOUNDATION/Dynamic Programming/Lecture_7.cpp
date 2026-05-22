#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<vector<int>>>> dp;
int cheerypickup(vector<vector<int>> mat,int row1,int col1,int row2, int col2){
if(row1<0 || col1<0 || row2<0 || col2<0 || mat[row1][col1] == -1 || mat[row2][col2] == -1){
    return INT_MIN;
}
if(row1 == 0 && col1 == 0 && row2 == 0 && col2 == 0){
    return mat[row1][col1];
}
if(dp[row1][col1][row2][col2] != -1){
    return dp[row1][col1][row2][col2];
}
int t1 = cheerypickup(mat,row1-1,col1,row2-1,col2);
int t2 = cheerypickup(mat,row1,col1-1,row2,col2-1);
int t3 = cheerypickup(mat,row1-1,col1,row2,col2-1);
int t4 = cheerypickup(mat,row1,col1-1,row2-1,col2);
int ans = max({t1,t2,t3,t4});
int contri = 0;
if(row1 == row2 && col1 == col2){
    contri = mat[row1][col1];
} else {
    contri = mat[row1][col1] + mat[row2][col2];
}
dp[row1][col1][row2][col2] = ans + contri;
return dp[row1][col1][row2][col2];
}
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>> mat(n,vector<int>(m));
for(int i =0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>mat[i][j];
    }
}
dp.resize(n,
    vector<vector<vector<int>>>(
        n,
        vector<vector<int>>(
            n,
            vector<int>(
                n,
                -1
            )
        )
    )
);
int ans = cheerypickup(mat,n-1,m-1,n-1,m-1);
cout<<ans<<endl;
return 0;
}
