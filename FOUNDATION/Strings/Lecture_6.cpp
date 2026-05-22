#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
string s;
cin>>s;
cout<<s<<endl<<"------******-------"<<endl;
for(int i = 0; i<s.size(); i++){
    if(s[i]>='A' && s[i]<='Z'){
        s[i] = (char)(s[i] + 32);
    } else {
        s[i] = (char)(s[i]- 32);
    }
}
cout<<s<<endl;
return 0;
}