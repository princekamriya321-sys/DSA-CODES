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
int main() {
int a,b;
cin>>a>>b;
int ans = gcd(a,b);
cout<<ans<<endl;
return 0;
}