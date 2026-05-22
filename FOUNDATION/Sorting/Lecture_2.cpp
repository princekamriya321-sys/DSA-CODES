#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int removalorder(vector<int> &arr){
sort(arr.begin(), arr.end());
int ans = 0;
int n = arr.size();
for(int i = n-1; i>=0; i--){
ans += arr[i]*(n-(i));
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
int ans = removalorder(arr);
cout<<ans<<endl;
return 0;
}