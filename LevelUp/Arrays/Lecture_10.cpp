#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Validsubarray(vector<int>& arr,int left,int right){
    int ans = 0;
    int n = arr.size();
    int lgeip1 = 0; 
    int prevvalidcount = 0;
    for(int ep = 0; ep<n; ep++){
        if(arr[ep]> right){
            ans += 0;
            prevvalidcount = 0;
            lgeip1 = ep + 1;
        } else if(arr[ep]>=left && arr[ep]<=right){
            prevvalidcount = ep - lgeip1 + 1;
            ans += ep-lgeip1+1;
        } else {
            ans += prevvalidcount;
        }
    }
    return ans;
}
int main() {
int n,l,r;  
cin>>n>>l>>r;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = Validsubarray(arr,l,r);
cout<<ans<<endl;
return 0;
}