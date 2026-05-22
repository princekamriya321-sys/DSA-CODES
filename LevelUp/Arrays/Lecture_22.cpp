#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Prefixmax(vector<int> &arr){
int n = arr.size();
vector<int> prefixmax(n);
prefixmax[0] = arr[0];
for(int i = 1; i<n; i++){
prefixmax[i] = max(prefixmax[i-1],arr[i]);
}
return prefixmax;
}
vector<int> Suffixmax(vector<int> &arr){
int n = arr.size();
vector<int> suffixmin(n);
suffixmin[n-1] = arr[n-1];
for(int i = n-2; i>=0; i--){
suffixmin[i] = min(suffixmin[i+1],arr[i]);
}
return suffixmin;
}
int Maxchunks2(vector<int> &arr){
    int n = arr.size();
    vector<int> prefixmax = Prefixmax(arr);
    vector<int> suffixmin = Suffixmax(arr);
    int count = 0;
    for(int i =0; i<n-1; i++){
        if(prefixmax[i] <= suffixmin[i+1]){
            count++;
        }
    }
    count++;
   return count;
}
int main() {
int n; 
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = Maxchunks2(arr);
cout<<ans<<endl;
return 0;
}