#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Add virtual balloons
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // len = length of interval
    for(int len = 1; len <= n; len++)
    {
        // left boundary
        for(int left = 1; left <= n - len + 1; left++)
        {
            int right = left + len - 1;

            // Assume k is burst last
            for(int k = left; k <= right; k++)
            {
                int coins =
                    dp[left][k - 1] +
                    dp[k + 1][right] +
                    nums[left - 1] * nums[k] * nums[right + 1];

                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    return dp[1][n];
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