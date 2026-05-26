
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int rearrange(vector<int> &arr){
    int n = arr.size();
   int p1 = 1;
   int p2 = n-1;
   while(p1 <= p2){
if(arr[p1]<arr[0]){
    p1++;
} else if(arr[p2]> arr[0]){
    p2--;
} else {
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
    p1++;
    p2--;
}
   }
   return p2;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int temp = rearrange(arr);
int t = arr[0];
arr[0] = arr[temp];
arr[temp] = t;
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}