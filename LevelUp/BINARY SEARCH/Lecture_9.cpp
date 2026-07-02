#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool SM2(vector<vector<int>> &arr,int target){
int n = arr.size();
int m = arr[0].size();
int i = 0; 
int j = m-1;
while(i<n && j>=0){
if(arr[i][j] == target) return true;
if(arr[i][j] > target){
    j--;
} else {
    i++;
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
bool ans = SM2(arr,target);
cout<<ans<<endl;
return 0; 
}