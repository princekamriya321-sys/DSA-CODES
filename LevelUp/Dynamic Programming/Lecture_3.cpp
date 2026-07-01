#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int helper(vector<int> &wt, vector<int> &val, int idx,int k){
if(idx == -1 || k<0) return 0;
if(dp[idx][k] != -1) return dp[idx][k];
int x = helper(wt,val,idx-1,k);
int y = 0;
if(wt[idx] <= k){
y = helper(wt,val,idx,k-wt[idx]) + val[idx];
}
return dp[idx][k] = max(x,y);
}
int knapsack(vector<int> &wt, vector<int> &val, int K)
{
int n = wt.size();
dp.assign(n+1,vector<int>(K+1,-1));
int idx = n-1;
return helper(wt,val,idx,K);
}

int main()
{
    int n;
    cin >> n;

    vector<int> wt(n), val(n);

    for(int i = 0; i < n; i++)
        cin >> wt[i];

    for(int i = 0; i < n; i++)
        cin >> val[i];

    int K;
    cin >> K;

    cout << knapsack(wt, val, K);

    return 0;
}