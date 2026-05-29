#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0)return b;
    int temp = gcd(b%a,a);
    return temp;
}
int numberofsubarraygcd(vector<int> &arr,int k){
    int n = arr.size();
int count = 0;
for(int i =0; i<n; i++){
    int ans = 0;
    for(int j = i; j<n; j++){
        ans = gcd(ans,arr[j]);
        if(ans == k) count++;
        if(ans <k) break;
    }
}
return count;
}
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = numberofsubarraygcd(arr,k);
cout<<ans<<endl;
return 0;
}