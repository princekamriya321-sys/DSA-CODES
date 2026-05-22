#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fibbo(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    int temp1 = fibbo(n-1);
    int temp2 = fibbo(n-2);
    int ans = temp1 + temp2;
    return ans;
}
int main() {
int n;
cin>>n;
int ans = fibbo(n);
cout<<ans<<endl;
return 0;
}