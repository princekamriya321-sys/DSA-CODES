#include<bits/stdc++.h>
//Optimised Code
using namespace std;
vector<int>dp;
int LIS(vector<int> &arr)
{
int n = arr.size();
dp.assign(n,0);
int ans = 0;
for(int i =0; i<n; i++){
    int lo = 0;
    int hi = ans;
    while(lo<hi){
        int m = lo + (hi-lo)/2;
        if(dp[m] < arr[i]){
        lo = m+1;
        } else {
            hi = m;
        }
    }
    dp[lo] = arr[i];
    if(lo == ans){
        ans++;
    }
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