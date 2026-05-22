#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void printnumber(int n){
    if(n == 0){
        return;
    }
    printnumber(n-1);
    cout<<n<<endl;
    return;
}
int main() {
int n;
cin>>n;
printnumber(n);
return 0;
}