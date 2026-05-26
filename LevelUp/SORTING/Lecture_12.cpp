
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void wigglesort(vector<int> &arr){
    int n = arr.size();
    for(int i =0; i<n-1; i++){
        if(i%2 == 0){
          if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
             }
        } else {
         if(arr[i] < arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
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
wigglesort(arr);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}