#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int count(vector<int> &dist,int m){
    int cows = 1;
    int lastpos = dist[0];
    for(int v : dist){
        if(v - lastpos >= m){
            cows++;
            lastpos = v;
        }
    }
    return cows;
}
int maxdist(vector<int> &dist,int k){
int n = dist.size();
int lo = INT_MAX;
int hi = dist[n-1]- dist[0];
for(int i = 0; i<n-1; i++){
    lo = min(dist[i+1]-dist[i],lo);
}
lo = min(lo,dist[n-1] - dist[n-2]);
int ans = -1;
while(lo<=hi){
    int m = lo + (hi-lo)/2;
    int cowplaced = count(dist,m);
    if(cowplaced >= k){
        ans = m;
        lo = m+1;
    } else{
     hi = m-1;
    }
}
return ans;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> dist(n);
for(int i =0; i<n; i++){
    cin>>dist[i];
}
int ans = maxdist(dist,k);
cout<<ans<<endl;
return 0; 
}