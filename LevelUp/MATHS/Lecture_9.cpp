#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0)return b;
    int temp = gcd(b%a,a);
    return temp;
}
vector<int> smallestprime(int n){
    vector<int> arr(n+1);
    arr[0] = -1;
    arr[1] = -1;
    for(int i = 2; i<=n; i++){
        arr[i] = i;
    }
    for(int i = 2; i*i<=n; i++){
        if(arr[i] == i){
            for(int j = i*i; j<=n; j+=i){
                arr[j] = min(arr[j],i);
            }
        }
    }
    return arr;
}
int main() {
int n;
cin>>n;
vector<int> ans = smallestprime(n);
for(int i = 0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}