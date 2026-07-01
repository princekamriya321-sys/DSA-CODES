#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int helper(string s1,int idx1,string s2, int idx2){
    if(idx1 == -1 || idx2 == -1) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(s1[idx1] == s2[idx2]){
        int x = helper(s1,idx1-1,s2,idx2-1);
        return dp[idx1][idx2] = x + 1;
    } else {
int x = helper(s1,idx1-1,s2,idx2);
int y = helper(s1,idx1,s2,idx2-1);
return dp[idx1][idx2] = max(x,y);
    }
}
int LCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
dp.assign(n+1,vector<int>(m+1,-1));
int idx1 = n-1;
int idx2 = m-1;
return helper(s1,idx1,s2,idx2);
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    cout << LCS(s1, s2);

    return 0;
}