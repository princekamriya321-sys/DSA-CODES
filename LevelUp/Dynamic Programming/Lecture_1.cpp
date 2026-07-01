#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int helper(vector<int> &arr,int idx){
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
int x = helper(arr,idx-1);
int y = helper(arr,idx-2) + arr[idx];
return dp[idx] = max(x,y);
}
int maxSubsequenceSum(vector<int> &arr)
{
    int n = arr.size();
    dp.assign(n+1,-1);
    int i =n-1;
 return helper(arr,i);
}
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nMaximum Subsequence Sum = "
         << maxSubsequenceSum(arr);

    return 0;
}