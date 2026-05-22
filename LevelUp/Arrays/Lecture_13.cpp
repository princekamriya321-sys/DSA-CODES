#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Rotatenintydegree(vector<vector<int>> &arr){
int n = arr.size();
int m = arr[0].size();
for(int i = 1; i<n; i++){
    for(int j = 0; j<i; j++){
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
}
for(int i =0; i<n; i++){
    int right = n-1;
    int left = 0;
    while(left<right){
        int temp = arr[i][left];
        arr[i][left] = arr[i][right];
        arr[i][right] = temp;
        right--;
        left++;
    }
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
Rotatenintydegree(arr);
for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
        cout<<arr[i][j]<<" ";
}
cout<<endl;
}
return 0;
}