#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int uniqueelement(vector<int>&arr){
int n = arr.size();
int lo = 2;
int hi = n-3;
if(arr[0] != arr[1]){
    return arr[0];
}
if(arr[n-2] != arr[n-1]){
    return arr[n-1];
}
int ans = -1;
while(lo <= hi){
    int mid = lo + (hi-lo)/2;
    if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
       return arr[mid];
    } 
    if(arr[mid] == arr[mid -1]){
        mid--;
    }
    if(mid % 2 == 0){
        lo = mid+2;
    } else {
        hi = mid - 1;
    }
}
return ans;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = uniqueelement(arr);
cout<<ans<<endl;
return 0;
}