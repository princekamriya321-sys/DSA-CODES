#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ValidParentheses(string s){
stack<char> st;
int n = s.size();
for(int i = 0; i<n; i++){
if(st.size() == 0 || s[i] == '(' || s[i] == '{' || s[i] == '['){
    st.push(s[i]);
} else {
    if(s[i] == ')'){
        if(st.top() == '('){
            st.pop();
        } else {
            return false;
        }
    } else if(s[i] == '}'){
        if(st.top() == '{'){
            st.pop();
        } else {
            return false;
        } 
    } else if(s[i] == ']'){
        if(st.top() == '['){
            st.pop();
        } else {
            return false;
        }
    }
}
}
if(st.size() == 0){
    return true;
} else {
    return false;
}
}
int main() {
string s;
cin>>s;
bool ans = ValidParentheses(s);
cout<<ans<<endl;
return 0;
}