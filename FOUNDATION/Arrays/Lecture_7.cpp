#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void swap(vector<int> &arr){
    int n = arr.size();
   int st = 0;
   int ed = n-1;
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
for(int i = 0; i<n; i++){
  cout<<arr[i]<<" ";
}
cout<<"         "<<endl;
swap(arr);
for(int i = 0; i<n; i++){
  cout<<arr[i]<<" ";
}
return 0;
}