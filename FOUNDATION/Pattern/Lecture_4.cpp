#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
int st = n/2 + 1;
int sp = 1;
for(int i = 1; i<=n; i++){
    for(int j = 1; j<= st; j++){
        cout<<"*";
    }
    for(int j = 1; j<=sp; j++){
        cout<<" ";
    }
    for(int j = 1; j<= st; j++){
        cout<<"*";
    }
    if(i<= n/2){
        sp += 2;
        st -= 1;
    } else {
        sp -= 2;
        st += 1;
    }
    cout<<endl;
}
return 0;
}