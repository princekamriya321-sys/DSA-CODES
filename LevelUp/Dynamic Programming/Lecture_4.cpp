#include <bits/stdc++.h>
using namespace std;
//Maximum path sum
int main() {

    vector<vector<int>> grid = {
        {2, 5, 10},
        {3, 9, 13},
        {12, 11, 18}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];

    // First row
    for(int j = 1; j < m; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // First column
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Remaining cells
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){

            dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);

        }
    }

    cout << "DP Table:\n";

    for(auto &row : dp){
        for(int x : row)
            cout << x << " ";
        cout << endl;
    }

    cout << "\nMaximum Path Sum = " << dp[n-1][m-1] << endl;

    return 0;
}