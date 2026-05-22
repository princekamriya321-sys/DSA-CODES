#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Printboundary(vector<vector<int>> &arr){
int n = arr.size();
int m = arr[0].size();
int i = 0;
int j =0;
int rsteps = n-1;
int csteps = m-1;
while(rsteps >= 1 && csteps >=1){
for(int k = 0; k<csteps; k++){
    cout<<arr[i][j]<<" ";
    j++;
}
for(int k = 0; k<rsteps; k++){
    cout<<arr[i][j]<<" ";
    i++;
}
for(int k = 0; k<csteps; k++){
    cout<<arr[i][j]<<" ";
    j--;
}
for(int k = 0; k<rsteps; k++){
    cout<<arr[i][j]<<" ";
    i--;
}
i++;
j++;
rsteps -= 2;
csteps -= 2;
}
if(rsteps == 0){
    for(int k = 0; k<csteps+1; k++){
        cout<<arr[i][j]<<" ";
        j++;
    }
} else if(csteps == 0){
    for(int k = 0; k<rsteps+1; k++){
        cout<<arr[i][j]<<" ";
        i++;
    }
}
}
int main() {
int n,m;  
cin>>n>>m;
vector<vector<int>> arr(n,vector<int>(m));
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>arr[i][j];
}
}
Printboundary(arr);
return 0;
}