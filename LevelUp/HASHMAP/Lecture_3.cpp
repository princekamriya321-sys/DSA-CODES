#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> func1(vector<int> &arr){
    int n = arr.size();
    vector<int> prefixsum(n);
    int sum =0;
    for(int i =0; i<n; i++){
        sum += arr[i];
        prefixsum[i] = sum;
    }
    return prefixsum;
}
int subarraysum(vector<int> &arr,int k){
    vector<int> psum = func1(arr);
    int n = arr.size();
    int ans = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;
for(int ep = 0; ep<n; ep++){
int diff = psum[ep] - k;
    ans += mp[diff];
mp[psum[ep]]++;
}
return ans;
}
int main() {
int n,k;
cin>>n>>k;
vector<int>arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = subarraysum(arr,k);
cout<<ans<<endl;
return 0;
}