#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Printboundary(vector<vector<int>> &arr){
int n = arr.size();
int i = 0;
int j =0;
int steps = n-1;
while(steps >= 1){
for(int k = 0; k<steps; k++){
    cout<<arr[i][j]<<" ";
    j++;
}
for(int k = 0; k<steps; k++){
    cout<<arr[i][j]<<" ";
    i++;
}
for(int k = 0; k<steps; k++){
    cout<<arr[i][j]<<" ";
    j--;
}
for(int k = 0; k<steps; k++){
    cout<<arr[i][j]<<" ";
    i--;
}
i++;
j++;
steps -= 2;
}
if(steps == 0){
    cout<<arr[i][j]<<" ";
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