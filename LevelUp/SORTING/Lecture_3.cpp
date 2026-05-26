
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void merge(vector<int> &arr,int s,int m,int e){
int n = arr.size();
vector<int> ans(e-s+1);
int p1 = s;
int p2 = m+1;
int p3 = 0;
while(p1<=m && p2<=e){
    if(arr[p1]>arr[p2]){
        ans[p3] = arr[p2];
        p2++;
        p3++;
    } else {
        ans[p3] = arr[p1];
        p1++;
        p3++;
    }
}
while(p1<=m){
    ans[p3] = arr[p1];
    p1++;
    p3++;
}
while(p2<=e){
     ans[p3] = arr[p2];
        p2++;
        p3++;
}
for(int i = 0; i<ans.size(); i++){
    arr[s+i] = ans[i];
}
}
int main() {
int n,s,m,e;
cin>>n>>s>>m>>e;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
merge(arr, s,m, e);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}