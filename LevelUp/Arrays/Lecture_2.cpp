#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Prefixsum(vector<int> &arr,vector<vector<int>> &queries){
int n = arr.size();
int q = queries.size();
for(int i = 0; i<q; i++){
int l = queries[i][0];
int r = queries[i][1];
int sum = 0;
for(int j = l; j<=r; j++){
sum += arr[j];
}
cout<<sum<<" ";
}
}
int main() {
int n,q;
cin>>n>>q;
vector<int> arr(n);
vector<vector<int>> queries(q,vector<int>(2));
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
for(int i = 0; i<q; i++){
for(int j = 0; j<2; j++){
   cin>>queries[i][j];
}
}
Prefixsum(arr,queries);
return 0;
}