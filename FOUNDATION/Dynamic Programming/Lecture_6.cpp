#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int pathcount(int i,int j){
if(i == 0 || j == 0){
    return 1;
}
if(dp[i][j] != -1){
    return dp[i][j];
}
int x = pathcount(i,j-1);
int y = pathcount(i-1,j);
dp[i][j] = x+y;
return dp[i][j];
}
int main(){
int n,m;
cin>>n>>m;
dp.resize(n,vector<int>(m,-1));
int ans = pathcount(n-1,m-1);
cout<<ans<<endl;
return 0;
}
