
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool checkbit(int n,int r){
    int x = 1<<r;
    if(n & x){
        return true;
    } else {
        return false;
    }
}
vector<vector<int>> Subseq(vector<int> &arr){
    int n = arr.size();
    int total = 1<<n;
    vector<vector<int>> ans;
    for(int i= 0; i<total; i++){
vector<int> temp;
for(int j =0; j<n; j++){
if(checkbit(i,j) == true){
    temp.push_back(arr[j]);
}
}
ans.push_back(temp);
    }
    return ans;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
vector<vector<int>> ans = Subseq(arr);
for(int i =0; i<ans.size(); i++){
cout<<"{";
for(int x: ans[i]){
cout<<x<<" ";
}
cout<<"}"<<endl;
}
return 0;
}