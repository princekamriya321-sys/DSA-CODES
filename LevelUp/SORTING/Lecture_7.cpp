
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void insertionsort(vector<int> &arr){
    int n = arr.size();
   for(int i = 1; i<n; i++){
    for(int j = i-1; j>=0; j--){
        if(arr[j+1]<arr[j]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
        } else {
            break;
        }
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
insertionsort(arr);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}