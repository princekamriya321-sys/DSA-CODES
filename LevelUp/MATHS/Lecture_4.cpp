#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0){
        return b;
    }
int temp = gcd(b%a,a);
return temp;
}
bool gcdsubseq(vector<int> &arr){
    int n = arr.size();
    int ans = arr[0];
for(int i =1; i<n; i++){
    ans = gcd(ans,arr[i]);
}
if(ans == 1){
    return true;
} else {
    return false;
}
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
bool ans = gcdsubseq(arr);
cout<<ans<<endl;
return 0;
}