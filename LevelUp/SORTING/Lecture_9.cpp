
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int rearrange(vector<int> &arr,int s,int e){
    int n = arr.size();
   int p1 = s+1;
   int p2 = e;
   while(p1 <= p2){
if(arr[p1]<arr[s]){
    p1++;
} else if(arr[p2]> arr[s]){
    p2--;
} else {
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
    p1++;
    p2--;
}
   }
int temp = arr[s];
arr[s] = arr[p2];
arr[p2] = temp;
   return p2;
}
void quicksort(vector<int> &arr,int s,int e){
    if(s>=e){ return;}
int p = rearrange(arr,s,e);
quicksort(arr,s,p-1);
quicksort(arr,p+1,e);
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
quicksort(arr,0,n-1);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}