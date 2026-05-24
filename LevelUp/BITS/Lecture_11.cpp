#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int divideinteger(int a,int b){
    if(a == INT_MIN && b == -1){
        return INT_MAX;
    } else if(b == INT_MIN && a == -1){
        return INT_MAX;
    }
    long long A = llabs((long long) a);
    long long B = llabs((long long)b);
    int sign = 1;
    if(A< 0){
        sign = -1*sign;
    } 
    if(B<0){
        sign =-1*sign;
    } 
    A = abs(A);
    B = abs(B);
    if(B>A){
        int temp = A;
        A = B;
        B = temp;
    }
    long long q = 0;
    long long temp = 0;
    for(int i =31; i>=0; i--){
        if(temp + (B<<i) <= A){
            temp = temp + (B<<i);
            q += ((long long)1<<i);
        }
    }
    if(sign < 0){
        q = -q;
    }
    if(q > INT_MAX){
        return INT_MAX;
    }
    if(q<INT_MIN){
        return INT_MIN;
    }
    return (int)q;
}
int main() {
int a,b;
cin>>a>>b;
int ans = divideinteger(a,b);
cout<<ans<<endl;
return 0;
}