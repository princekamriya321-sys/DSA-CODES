#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int helper(string &s1,int i,string &s2,int j){
    if(i == -1 && j == -1) return 0;
    if(i == -1 && j != -1) return j+1;
    if(i != -1 && j == -1) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        int x = helper(s1,i-1,s2,j-1);
       return dp[i][j] = x;
    } else {
    int x = helper(s1,i-1,s2,j);// delete
    int y = helper(s1,i-1,s2,j-1); // replace
    int z = helper(s1,i,s2,j-1);  // add
    return dp[i][j] = min(min(x+1,y+1),z+1);
    }
}
int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
dp.assign(n,vector<int>(m,-1));
int i = n-1;
int j = m-1;
return helper(s1,i,s2,j);
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);

    return 0;
}