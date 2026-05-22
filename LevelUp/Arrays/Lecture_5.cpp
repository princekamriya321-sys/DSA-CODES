#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Prefixmax(vector<int> &arr){
    int n = arr.size();
    vector<int> prefixmax(n);
    prefixmax[0] = arr[0];
    for(int i = 1; i<n; i++){
prefixmax[i] = max(prefixmax[i-1],arr[i]);
    }
    return prefixmax;
}
vector<int> Suffixmax(vector<int> &arr){
    int n = arr.size();
    vector<int> suffixmax(n);
    suffixmax[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
suffixmax[i] = max(suffixmax[i+1],arr[i]);
    }
    return suffixmax;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
vector<int> prefixmax = Prefixmax(arr);
vector<int> suffixmax = Suffixmax(arr);
vector<int> ans(n);
int amount = 0;
for(int i =1; i<n-1; i++){
    int lb =prefixmax[i-1];
    int rb = suffixmax[i+1];
    int yb = min(lb,rb) - arr[i];
    if(yb>0){
    amount+= yb;
    } 
}
cout<<amount<<endl;
return 0;
}