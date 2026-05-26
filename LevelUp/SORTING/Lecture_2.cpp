
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> merge(vector<int> &a,vector<int> &b){
    int n = a.size();
    int m = b.size();
vector<int> ans(n+m);
int p1 = 0;
int p2 = 0;
int p3 = 0;
while(p1<n && p2<m){
    if(a[p1]>b[p2]){
        ans[p3] = b[p2];
        p2++;
        p3++;
    } else {
        ans[p3] = a[p1];
        p1++;
        p3++;
    }
}
while(p1<n){
    ans[p3] = a[p1];
    p1++;
    p3++;
}
while(p2<m){
     ans[p3] = b[p2];
        p2++;
        p3++;
}
return ans;
}
int main() {
int n;
cin>>n;
vector<int> a(n);
for(int i =0; i<n; i++){
    cin>>a[i];
}
int m;
cin>>m;
vector<int> b(m);
for(int i =0; i<m; i++){
    cin>>b[i];
}
vector<int> ans = merge(a,b);
for(int i = 0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}