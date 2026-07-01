#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> dp;
int countPalindromicSubstring(string s)
{
int n = s.size();
dp.assign(n,vector<bool>(n,false));

for(int l = 1; l<=n; l++){
    for(int i = 0; i+l-1<n; i++){
        int j= l+i-1;
        if(i == j){
        dp[i][j] = true;
        } else if(i+1 == j){
            dp[i][j] = (s[i] == s[j]);
        } else {
            dp[i][j] = (s[i]== s[j] && dp[i+1][j-1]);
        }
    } 
}
int ans = 0;
for(int i =0; i<n; i++){
    for(int j =0; j<n; j++){
        if(dp[i][j])ans++;
    }
}
return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << countPalindromicSubstring(s);

    return 0;
}