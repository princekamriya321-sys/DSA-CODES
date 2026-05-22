#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Prefixproduct(vector<int> &arr){
int n = arr.size();
int product = 1;
vector<int> prefixprd(n);
for(int i = 0; i<n; i++){
product *= arr[i];
prefixprd[i] = product;
}
return prefixprd;
}
vector<int> Productnumber(vector<int> &arr,vector<int> &prefixprd){
int n = arr.size();
if(n == 1){
    prefixprd[0] = 0;
    return prefixprd;
}
int suffix = 1;
for(int i = n-1; i>=1; i--){
prefixprd[i] = prefixprd[i-1]*suffix;
suffix *= arr[i];
}
prefixprd[0] = suffix;
return prefixprd;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
vector<int> prefixprd = Prefixproduct(arr);
vector<int> ans = Productnumber(arr,prefixprd);
for(int i = 0; i<n; i++){
    cout<<ans[i]<<" ";
}
return 0;
}