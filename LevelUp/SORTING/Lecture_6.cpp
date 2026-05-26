
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void insertelement(vector<int> &arr){
    int n = arr.size();
    for(int i = n-2; i>=0; i--){
        if(arr[i+1]< arr[i]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
insertelement(arr);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}