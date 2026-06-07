#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> func1(vector<int> &arr){
    int n = arr.size();
    vector<int> pc0(n);
    if(arr[0] == 0){
        pc0[0] = 1;
    }  else {
        pc0[0] = 0;
    }
    for(int i = 1; i<n; i++){
        if(arr[i] == 0){
            pc0[i] = pc0[i-1]+1;
        } else {
            pc0[i] = pc0[i-1];
        }
    }
    return pc0;
}
vector<int> func2(vector<int> &arr){
    int n = arr.size();
    vector<int> pc1(n);
    if(arr[0] == 1){
        pc1[0] = 1;
    }  else {
        pc1[0] = 0;
    }
    for(int i = 1; i<n; i++){
        if(arr[i] == 1){
            pc1[i] = pc1[i-1]+1;
        } else {
            pc1[i] = pc1[i-1];
        }
    }
    return pc1;
}
int countsubarray01(vector<int> &arr){
int n = arr.size();
unordered_map<int,int> mp;
vector<int> pc0 = func1(arr);
vector<int> pc1 = func2(arr);
int ans = 0;
mp[0] = 1;
for(int i = 0; i<n; i++){
    int diff = pc0[i] - pc1[i];
    ans += mp[diff];
    mp[diff]++;
}
return ans;
}
int main() {
int n;
cin>>n;
vector<int>arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = countsubarray01(arr);
cout<<ans<<endl;
return 0;
}