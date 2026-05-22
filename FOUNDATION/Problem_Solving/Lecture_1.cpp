#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
int count = 0;
for(int i = 1; i*i<=n; i++){
    if(n%i == 0){
        if(n/i == i){
            count++;
        } else {
            count += 2;
        }
    }
}
cout<<count<<endl;
return 0;
}