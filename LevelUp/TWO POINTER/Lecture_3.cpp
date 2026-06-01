#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void sort2(vector<int> &arr){
    int n = arr.size();
    int i = 0;
    int j = 0; 
    int k = n-1;
    while(j<=k){
        if(arr[j] == 0){
            int tem = arr[i];
            arr[i] = arr[j];
            arr[j] = tem;
            i++;
            j++;
        } else if(arr[j] == 1){
            j++;
        } else {
            int temp= arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            k--;
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
sort2(arr);
for(int i =0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}