#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Pivotidx(vector<int> &arr){
int n = arr.size();
int total_sum = 0;
for(int i = 0; i<n; i++){
    total_sum += arr[i];
}
int lsum = 0;
for(int i =0; i<n; i++){
    int rsum = 0;
    if(i != 0){
    lsum += arr[i-1];
    }
    rsum = total_sum - lsum - arr[i];
    if(lsum == rsum){
        return i;
    }
}
return -1;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = Pivotidx(arr);
cout<<ans<<endl;
return 0;
}