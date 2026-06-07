#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> gridillusion(int n, vector<vector<int>> &lamps,vector<vector<int>> queries){
    unordered_map<long long,int>m1;
    unordered_map<long long,int>m2;
    unordered_map<long long,int>m3;
    unordered_map<long long,int>m4;
    unordered_map<long long,int>m5;
    for(int i = 0; i<lamps.size(); i++){
        long long x = lamps[i][0];
        long long y = lamps[i][1];
        long long key = 1LL*x*n + y;

        if(m5[key] > 0) continue;
        m1[x]++;
        m2[y]++;
        m3[x-y]++;
        m4[x+y]++;
        m5[1LL*x*n + y]++;
    }
    vector<vector<int>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{-1,-1},{0,-1},{1,-1},{0,0}};
    vector<int> ans(queries.size());
for(int i =0; i<ans.size(); i++){
    long long x = queries[i][0];
    long long y = queries[i][1];
    if(m1[x]>0 || m2[y]>0 || m3[x-y]>0 || m4[x+y]>0){
        ans[i] = 1;
    } else {
        ans[i] = 0;
    }
    for(int d = 0; d<dir.size(); d++){
        int x1 = x + dir[d][0];
        int y1 = y + dir[d][1];
        if(x1>= 0 && y1>= 0 && x1<n && y1<n && m5[x1*n + y1] > 0){
            int times = m5[x1*n + y1];
            m1[x1] = m1[x1] - times;
            m2[y1] = m2[y1] - times;
            m3[x1 - y1] = m3[x1 - y1] - times;
            m4[x1 + y1] = m4[x1+ y1] - times;
            m5[1LL*x1*n + y1] -= times;
        }
    }
}
return ans;
}
int main() {
int n,l,q;
cin>>n>>l>>q;
vector<vector<int>> lamps(l,vector<int>(2));
vector<vector<int>> queries(q,vector<int>(2));
for(int i =0; i<l; i++){
for(int j =0; j<2; j++){
    cin>>lamps[i][j];
}
}
for(int i =0; i<q; i++){
for(int j =0; j<2; j++){
    cin>>queries[i][j];
}
}
vector<int> ans = gridillusion(n,lamps,queries);
for(int i =0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}
