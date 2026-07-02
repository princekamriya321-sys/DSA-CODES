#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int findmin2(vector<int> &arr){
int n = arr.size();
int lo = 0; 
int hi = n-1;
int ans = -1;
while(lo<=hi){
int m  = lo + (hi-lo)/2;
if(arr[m] == arr[lo] && arr[m] == arr[hi]){
    lo++;
    hi--;
} else if(arr[m] <= arr[hi]){
//right part sorted
if(ans == -1 || arr[m]< arr[ans]){
    ans = m;
}
hi = m-1;
} else {
// left part sorted
if(ans == -1 || arr[lo] < arr[ans]){
    ans = lo;
}
lo = m+1;
}
}
return arr[ans];
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = findmin2(arr);
cout<<ans<<endl;
return 0; 
}