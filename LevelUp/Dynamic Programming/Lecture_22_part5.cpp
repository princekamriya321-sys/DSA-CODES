#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
vector<vector<int>> dp;
int solve(vector<int> &stones,int curr_stone_idx,int prevjump){
    if(curr_stone_idx == stones.size()-1) return true;
    if(dp[curr_stone_idx][prevjump] != -1) return dp[curr_stone_idx][prevjump];
    bool result = false;
    for(int nextjump = prevjump-1; nextjump <= prevjump+1; nextjump++){
        if(nextjump > 0){
        int nextstone = stones[curr_stone_idx] + nextjump;
        if(mp.find(nextstone) != mp.end()){
            result = result || solve(stones,mp[nextstone],nextjump);
        }
        }
    }
    return dp[curr_stone_idx][prevjump] = result;
}
bool frogJump(vector<int> &stones)
{
   int n = stones.size();
   if(n<2) return true;
   dp.assign(n+1,vector<int>(n+1,-1));
   if(stones[1] != 1) return false;

for(int i =0; i<n; i++){
    mp[stones[i]] = i;
}
return solve(stones,0,0);
}

int main()
{
    int n;
    cin >> n;

    vector<int> stones(n);

    for(int i = 0; i < n; i++)
        cin >> stones[i];

    cout << frogJump(stones);

    return 0;
}