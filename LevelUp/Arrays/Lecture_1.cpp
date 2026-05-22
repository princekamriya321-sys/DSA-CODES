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
int main() {
int n;  
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
vector<int> prefixsum = Prefixsum(arr);
for(int i = 0; i<n; i++){
    cout<<prefixsum[i]<<" ";
}
return 0;
}