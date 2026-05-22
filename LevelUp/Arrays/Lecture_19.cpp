#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Missingpositivenumber2(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    int val1 = arr[0];
    int count1 = 1;
    int val2 = -1;
    int count2 = 0;
   for(int i = 0; i<n; i++){
    if(arr[i] == val1){
        count1++;
    } else if(arr[i] == val2){
        count2++;
    } else if(count1 == 0){
        val1 = arr[i];
        count1++;
    } else if(count2 == 0){
        val2 = arr[i];
        count2++;
    } else {
        count1--;
        count2--;
    }
   }
   int c1 = 0;
   int c2 = 0;
   for(int i = 0; i<n; i++){
    if(arr[i] == val1){c1++;}
    if(arr[i] == val2){c2++;}
   }
   if(c1 > n/3){
    ans.push_back(val1);
   }
   if(c2 > n/3){
    ans.push_back(val2);
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
vector<int> ans = Missingpositivenumber2(arr);
for(int i =0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}