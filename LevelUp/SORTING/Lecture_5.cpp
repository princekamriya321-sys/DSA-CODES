
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int ct = 0;
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
        ct += m-p1 + 1;
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
void mergesort(vector<int> &arr,int s,int e){
    if(s >= e) return;
    int m = s+(e-s)/2;
    mergesort(arr,s,m);
    mergesort(arr,m+1,e);
    merge(arr,s,m,e);
}
int main() {
int n,s,e;
cin>>n>>s>>e;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
mergesort(arr,s,e);
cout<<ct<<endl;
return 0;
}