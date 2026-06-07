#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int leastbricks(vector<vector<int>> &walls){
    unordered_map<int,int> mp;
    int ans = 0;
for(vector<int> biglist: walls){
    int len = 0;
    for(int i =0; i<biglist.size()-1; i++){
        len += biglist[i];
        mp[len]++;
        ans = max(ans,mp[len]);
    }
}
return walls.size() - ans;
}
int main() {
vector<vector<int>> walls;
walls.push_back({1,2,2,1});
walls.push_back({3,1,2});
walls.push_back({1,3,2});
walls.push_back({2,4});
walls.push_back({3,1,2});
walls.push_back({1,3,1,1});
int ans = leastbricks(walls);
cout<<ans<<endl;
return 0;
}