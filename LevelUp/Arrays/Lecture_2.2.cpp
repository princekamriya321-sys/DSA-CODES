#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Prefixsum(vector<int> &arr){
int n = arr.size();
int sum = 0;
vector<int> prefixsum(n);
for(int i = 0; i<n; i++){
sum += arr[i];
prefixsum[i] = sum;
}
return prefixsum;
}
void sumquery(vector<int> &arr,vector<vector<int>> &queries,vector<int> prefixsum){
int n = arr.size();
int q = queries.size();
for(int i =0; i<q; i++){
    int l = queries[i][0];
    int r = queries[i][1];
    int sum = 0;
    if(l>0){
        sum = prefixsum[r] - prefixsum[l-1];
    } else{
        sum = prefixsum[r];
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
vector<int> prefixsum = Prefixsum(arr);
sumquery(arr,queries,prefixsum);

return 0;
}