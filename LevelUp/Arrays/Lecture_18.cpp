#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Missingpositivenumber(vector<int> &arr){
    int n = arr.size();
    int val = arr[0];
    int count = 1;
    for(int i = 1; i<n; i++){
        if(arr[i] == val){
            count++;
        } else {
            if(count == 0){
                val = arr[i];
                count++;
            } else{
                count--;
            }
        }
    }
   return val;
}
int main() {
int n; 
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = Missingpositivenumber(arr);
cout<<ans<<endl;
return 0;
}