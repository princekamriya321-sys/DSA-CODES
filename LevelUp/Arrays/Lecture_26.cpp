#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Maxones(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i =0; i<n; i++){
        if(arr[i] == 0){
            arr[i] = 1;
        } else {
            arr[i] = -1;
            count++;
        }
    }  
int csum = 0;
int osum = INT_MIN;
for(int i = 0;i<n; i++){
    if(csum > 0){
        csum += arr[i];
    } else {
        csum = arr[i];
    }
    osum = max(csum,osum);
}
if(osum > 0){
    return osum + count;
} else {
    return count;
}
  
}
int main() {
int n; 
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = Maxones(arr);
cout<<ans<<endl;
return 0;
}