#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Kadanes(vector<int> &arr){
int n = arr.size();
int sum = 0;
int ans = INT_MIN;
for(int i =0; i<n; i++){
    if(sum >= 0){
        sum += arr[i];
    } else {
        sum = arr[i];
    }
    ans = max(ans,sum);
}
return ans;
}
int main() {
int n;  
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = Kadanes(arr);
cout<<ans<<endl;
return 0;
}