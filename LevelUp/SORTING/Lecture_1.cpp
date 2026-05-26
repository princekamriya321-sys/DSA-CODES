//Selection sort
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
int minidx = -1;
for(int i =0; i<n; i++){
int minele = arr[i];
for(int j = i+1; j<n; j++){
if(minele> arr[j]){
    minele = arr[j];
    minidx = j;
}
}
int temp = arr[i];
arr[i] = arr[minidx];
arr[minidx] = temp;
}
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}