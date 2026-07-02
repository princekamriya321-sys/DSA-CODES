#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool findrs(vector<int> &arr,int target){
int n = arr.size();
int lo = 0; 
int hi = n-1;
while(lo<=hi){
int m  = lo + (hi-lo)/2;
if(arr[m] == target){
    return true;
}
if(arr[m] == arr[lo] && arr[m] == arr[hi]){
    lo += 1;
    hi -= 1;
} else if(arr[m] <= arr[hi]){
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
return false;
}
int main() {
int n,target;
cin>>n>>target;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
bool ans = findrs(arr,target);
cout<<ans<<endl;
return 0; 
}