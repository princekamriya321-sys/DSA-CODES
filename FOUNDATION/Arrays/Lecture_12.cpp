#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void swap(vector<int> &arr, int s, int e){
    int n = arr.size();
   int st = s;
   int ed = e;
   while(st<=ed){
    int t = arr[st];
    arr[st] = arr[ed];
    arr[ed] = t;
    st++;
    ed--;
   }
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
int sum = 0;
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int k;
cin>>k;
// for(int i = 0; i<n; i++){
//   cout<<arr[i]<<" ";
// }
cout<<"*******      ------------     *******"<<endl;
swap(arr,0,n-1);
swap(arr,0,k-1);
swap(arr,k,n-1);
for(int i = 0; i<n; i++){
  cout<<arr[i]<<" ";
}
return 0;
}