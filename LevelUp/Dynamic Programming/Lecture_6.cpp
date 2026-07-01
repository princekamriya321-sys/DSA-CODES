#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};

    int W = 7;
    int n = wt.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= W; j++){

            // Not Pick
            dp[i][j] = dp[i-1][j];

            // Pick
            if(j >= wt[i-1]){
                dp[i][j] = max(dp[i][j],
                               val[i-1] + dp[i-1][j-wt[i-1]]);
            }
        }
    }

    cout << "DP Table:\n\n";

    for(auto &row : dp){
        for(int x : row)
            cout << setw(3) << x << " ";
        cout << endl;
    }

    cout << "\nMaximum Profit = " << dp[n][W];

    return 0;
}