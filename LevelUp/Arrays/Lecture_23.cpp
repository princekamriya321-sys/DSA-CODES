#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Printboundary(vector<vector<int>> &arr){
int n = arr.size();
int i = 0;
int j =0;
for(int k = 0; k<n-1; k++){
    cout<<arr[i][j]<<" ";
    j++;
}
for(int k = 0; k<n-1; k++){
    cout<<arr[i][j]<<" ";
    i++;
}
for(int k = 0; k<n-1; k++){
    cout<<arr[i][j]<<" ";
    j--;
}
for(int k = 0; k<n-1; k++){
    cout<<arr[i][j]<<" ";
    i--;
}
}
int main() {
int n;  
cin>>n;
vector<vector<int>> arr(n,vector<int>(n));
for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
        cin>>arr[i][j];
}
}
Printboundary(arr);
return 0;
}