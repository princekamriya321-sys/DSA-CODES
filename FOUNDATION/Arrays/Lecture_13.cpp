#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = 0;
int maxelem = INT_MIN;
int count = 0;
for(int i = 0; i<n; i++){
    if(arr[i] > maxelem){
maxelem = arr[i];
    }
}
for(int i = 0; i<n; i++){
    if(arr[i] == maxelem){
    count++;
    }
}
ans = n - count;
cout<<ans<<endl;

return 0;
}