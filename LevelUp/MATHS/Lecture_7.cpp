#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0)return b;
    int temp = gcd(b%a,a);
    return temp;
}
bool xofakind(vector<int> &arr){
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int i =0; i<n; i++){
        mp[arr[i]]++;
    }
    int ans = 0;
   for(auto it: mp){
    ans = gcd(ans,it.second);
    if(ans == false)return false;
   }
   return true;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
bool ans = xofakind(arr);
if(ans == true){
    cout<<"YES"<<endl;
} else {
        cout<<"NO"<<endl;
}
return 0;
}