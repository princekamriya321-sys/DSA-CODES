#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Binarysearch(vector<int>&arr,int k){
int lo = 0;
int hi = arr.size()-1;
int ans = -1;
while(lo <= hi){
    int mid = lo + (hi-lo)/2;
    if(arr[mid] == k){
       return k;
    } else if(arr[mid] > k){
    hi = mid -1;
} else {
    ans = arr[mid];
    lo = mid + 1;
    }
}

return ans;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = Binarysearch(arr,k);
cout<<ans<<endl;
return 0;
}