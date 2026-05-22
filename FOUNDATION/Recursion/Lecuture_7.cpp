#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int pow(int a,int b){
    if(b == 0){
        return 1;
    }
    return a*pow(a,b-1);
}
int main() {
int a,b;
cin>>a>>b;
int ans = pow(a,b);
cout<<ans<<endl;
return 0;
}