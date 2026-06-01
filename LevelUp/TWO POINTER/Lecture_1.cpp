#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool check(vector<int> &arr,int k){
    int n = arr.size();
int i =0;
int j = n-1;
while(i<j){
if(arr[i]+arr[j] > k){
    j--;
} else if(arr[i] + arr[j] < k){
    i++;
} else {
    return true;
}
}
return false;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
bool ans = check(arr,k);
cout<<ans<<endl;
return 0;
}