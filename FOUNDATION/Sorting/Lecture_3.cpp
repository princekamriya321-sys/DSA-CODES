#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int goodinteger(vector<int> &arr){
sort(arr.begin(), arr.end());
int ans = 0;
int n = arr.size();
for(int i = 0; i<n; i++){
    if(arr[i] == i){
        ans++;
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
int ans = goodinteger(arr);
cout<<ans<<endl;
return 0;
}