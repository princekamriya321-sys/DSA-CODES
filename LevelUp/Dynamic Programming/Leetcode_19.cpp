#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int helper(vector<int> &prices, int idx, int buy, int cap){

    if(idx == prices.size() || cap == 0)
        return 0;

    if(dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    if(buy){

        int take = -prices[idx] + helper(prices, idx+1, 0, cap);

        int skip = helper(prices, idx+1, 1, cap);

        return dp[idx][buy][cap] = max(take, skip);
    }
    else{

        int sell = prices[idx] + helper(prices, idx+1, 1, cap-1);

        int skip = helper(prices, idx+1, 0, cap);

        return dp[idx][buy][cap] = max(sell, skip);
    }
}

int maxProfit(vector<int> &prices){

    int n = prices.size();

    dp.assign(n,
              vector<vector<int>>(2,
              vector<int>(3, -1)));

    return helper(prices, 0, 1, 2);
}

int main(){

    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}