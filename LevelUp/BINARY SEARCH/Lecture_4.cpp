#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int findrs(vector<int> &arr,int target){
int n = arr.size();
int lo = 0; 
int hi = n-1;
while(lo<=hi){
int m  = lo + (hi-lo)/2;
if(arr[m] == target){
    return m;
}
if(arr[m] <= arr[hi]){
//right part sorted
if(arr[m]<=target && arr[hi]>= target){
    lo = m+1;
} else {
    hi = m-1;
}
} else {
if(arr[m]>= target && arr[lo] <= target){
    hi = m-1;
} else {
    lo = m+1;
}
}
}
return -1;
}
int main() {
int n,target;
cin>>n>>target;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = findrs(arr,target);
cout<<ans<<endl;
return 0; 
}