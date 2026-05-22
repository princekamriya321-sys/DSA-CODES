#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int factorial(int n){
    int ans = 1;
    for(int i = 1; i<=n; i++){
        ans = ans*i;
    }
    return ans;
}
int main() {
int n;
int r;
cin>>n>>r;
int a = factorial(n);
int b = factorial(r);
int c = factorial(n-r);
int ans = a/(b*c);
cout<<ans<<endl;
return 0;
}