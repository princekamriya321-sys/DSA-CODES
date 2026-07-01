#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int helper(vector<int> &nums,int s,int e){
    if(s > e) return 0;
if(dp[s][e] != -1) return dp[s][e];
int ans = 0;
for(int i = s; i<=e; i++){
    int leftans = helper(nums,s,i-1);
    int rightans = helper(nums,i+1,e);
    int myans = leftans + rightans + nums[s-1]*nums[i]*nums[e+1];
    ans = max(myans,ans);
}
dp[s][e] = ans;
return ans;
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    dp.assign(n + 2, vector<int>(n + 2, -1));

    return helper(nums, 1, n);
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maxCoins(nums);

    return 0;
}