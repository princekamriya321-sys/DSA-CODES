
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void countsort(vector<int> &arr){
    int maxele = INT_MIN;
    int n = arr.size();
    for(int i =0; i<n; i++){
        maxele = max(maxele,arr[i]);
    }
    vector<int> count(maxele+1);
    for(int i = 0; i<n; i++){
        count[arr[i]]++;
    }
    int k = 0;
    for(int i =0; i<count.size(); i++){
        int c = count[i];
        for(int j = 0; j<c; j++){
arr[k] = i;
k++;
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
countsort(arr);
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}