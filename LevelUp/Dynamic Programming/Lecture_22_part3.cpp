#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int ans = 0;
int LCS(string &s1,int i,string &s2,int j){
    if(i == s1.size() || j == s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
       LCS(s1,i+1,s2,j);
       LCS(s1,i,s2,j+1);
    if(s1[i] == s2[j]){
        int z = LCS(s1,i+1,s2,j+1) + 1;
     ans = max(ans,z);
      return dp[i][j] = z;
    } else {
      return dp[i][j] = 0;
    }
        return dp[i][j];
}
int longestCommonSubstring(string s1, string s2)
{
int n = s1.size();
int m = s2.size();
dp.assign(n,vector<int>(m,-1));
int i = 0;
int j =0;
ans = 0;
int x = LCS(s1,i,s2,j);
return ans;
}
int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    cout << longestCommonSubstring(s1, s2);

    return 0;
}