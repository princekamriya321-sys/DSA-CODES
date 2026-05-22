#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void bubblesort(vector<int> &arr){
    int n = arr.size();
for(int i = 0; i<n; i++){
    for(int j = 0; j<n-i-1; j++){
        if(arr[j] > arr[j+1]){
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
        }
    }
}
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
bubblesort(arr);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}