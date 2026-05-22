#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int pow(int a,int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    int temp = pow(a,b/2);
    if(b%2 != 0){
        return a*temp*temp;
    } else {
    return temp*temp;
    }
}
int main() {
int a,b;
cin>>a>>b;
int ans = pow(a,b);
cout<<ans<<endl;
return 0;
}