#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool SM(vector<vector<int>> &arr,int target){
int n = arr.size();
int m = arr[0].size();
int lo = 0; 
int hi = n*m-1;
while(lo<=hi){
int mid = lo + (hi-lo)/2;
int r =  mid/m;
int c = mid%m;
if(arr[r][c] == target) {return true;}
if(arr[r][c] > target){
    hi = mid - 1;
} else {
    lo = mid + 1;
}
}
return false;
}
int main() {
int n,m,target;
cin>>n>>m>>target;
vector<vector<int>> arr(n,vector<int>(m));
for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
        cin>>arr[i][j];
    }
}
bool ans = SM(arr,target);
cout<<ans<<endl;
return 0; 
}