#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int LIS(vector<int> &arr)
{
int n = arr.size();
dp.assign(n,1);
int ans = 1;
for(int i =1; i<n; i++){
    for(int j = i-1; j>=0; j--){
        if(arr[i] > arr[j]){
         dp[i] = max(dp[i],dp[j]+1);
        }
    }
    ans = max(ans,dp[i]);
} 
return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LIS(arr);

    return 0;
}