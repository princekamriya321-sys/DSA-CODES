#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>>dp;
int helper(string &s1,int i,string &s2, int j,string &s3,int k){
    if(i == -1 || j == -1 || k == -1) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(s1[i] == s2[j] && s1[i] == s3[k]){
        int x = helper(s1,i-1,s2,j-1,s3,k-1);
        return dp[i][j][k] = x + 1;
    } else {
int x = helper(s1,i-1,s2,j,s3,k);
int y = helper(s1,i,s2,j-1,s3,k);
int z = helper(s1,i,s2,j,s3,k-1);
return dp[i][j][k] = max(max(x,y),z);
    }
}
int LCS(string &s1, string &s2,string &s3)
{
    int n = s1.size();
    int m = s2.size();
    int k = s3.size();
dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
int idx1 = n-1;
int idx2 = m-1;
int idx3 = k -1;
return helper(s1,idx1,s2,idx2,s3,idx3);
}

int main()
{
    string s1, s2,s3;

    cin >> s1;
    cin >> s2;
    cin>> s3;
    cout << LCS(s1, s2,s3);

    return 0;
}