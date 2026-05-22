#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool TwoSum(vector<int> &arr, int k){
for(int i = 0; i<arr.size(); i++){
    for(int j = i+1; j<arr.size(); j++){
        if(arr[i] + arr[j] == k) return true;
    }
}
return false;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int k;
cin>>k;
bool ans = TwoSum(arr,k);
cout<<ans<<endl;
return 0;
}