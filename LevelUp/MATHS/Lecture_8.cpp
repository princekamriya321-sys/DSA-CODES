#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0)return b;
    int temp = gcd(b%a,a);
    return temp;
}
int allprimes(int n){
    vector<bool> arr(n,true);
    arr[0] = false;
    arr[1] = false;
    for(int i = 2; i*i<=n; i++){
        if(arr[i] == true){
            for(int j = i*i; j<=n; j+=i){
                arr[j] = false;
            }
        }
    }
        int count =0;
        for(int i =2; i<=n; i++){
            if(arr[i] == true){
                count++;
            }
        }
        return count;
}
int main() {
int n;
cin>>n;
int ans = allprimes(n);
cout<<ans<<endl;
return 0;
}