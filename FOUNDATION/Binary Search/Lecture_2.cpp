#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool Binarysearch(vector<int>&arr,int k){
int lo = 0;
int hi = arr.size()-1;
while(lo <= hi){
    int mid = lo + (hi-lo)/2;
    if(arr[mid] == k){
        return true;
    } else if(arr[mid] > k){
    hi = mid -1;
    } else {
lo = mid + 1;
    }
}
return false;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
bool ans = Binarysearch(arr,k);
cout<<ans<<endl;
return 0;
}