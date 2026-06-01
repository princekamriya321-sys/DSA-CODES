#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int maxwater(vector<int> &arr){
int n = arr.size();
int i =0;
int j = n-1;
int ans = INT_MIN;
while(i<j){
int w = (j-i)*min(arr[i],arr[j]);
if(arr[i] > arr[j]){
    j--;
} else {
    i++;
}
ans = max(ans,w);
}
return ans;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = maxwater(arr);
cout<<ans<<endl;
return 0;
}