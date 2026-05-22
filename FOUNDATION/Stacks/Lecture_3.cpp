#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string Removeadjacentelement(string s){
stack<char> st;
int n = s.size();
for(int i = 0; i<n; i++){
if(st.size() == 0 || st.top() != s[i]){
    st.push(s[i]);
} else {
    st.pop();
}
}
string ch;
while(!st.empty()){
  ch += st.top();
    st.pop();
}
reverse(ch.begin(),ch.end());
return ch;
}
int main() {
string s;
cin>>s;
string ans = Removeadjacentelement(s);
cout<<ans<<endl;
return 0;
}