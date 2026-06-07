#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int samedifference(vector<int> &arr){
int n = arr.size();
unordered_map<int,int> mp;
int ans = 0;
for(int i = 0; i<n; i++){
    int diff = arr[i] - i;
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
int ans = samedifference(arr);
cout<<ans<<endl;
return 0;
}