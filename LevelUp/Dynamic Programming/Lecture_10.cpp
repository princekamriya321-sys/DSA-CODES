#include<bits/stdc++.h>
using namespace std;

int buildingbridges(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    vector<pair<int,int>> arr(n);
for(int i = 0; i<n; i++){
    int x = envelopes[i][0];
    int y = envelopes[i][1];
    arr[i] = {x,y};
}
sort(arr.begin(),arr.end());
vector<int> dp(n,0);
int ans = 0;
for(int i = 0; i<n; i++){
    int lo = 0;
    int hi = ans;
    while(lo<hi){
        int m = lo + (hi-lo)/2;
        if(dp[m] < arr[i].second){
            lo = m+1;
        } else {
            hi = m;
        }
    }
    dp[lo] = arr[i].second;
    if(lo == ans) ans++;
}
return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> envelopes(n, vector<int>(2));

    cout << "Enter width and height of each envelope:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> envelopes[i][0] >> envelopes[i][1];
    }

    cout << buildingbridges(envelopes);

    return 0;
}