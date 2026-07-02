#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Minstack{
    public:
    stack<int> st;
   int minele = INT_MAX;
void push(int val){
if(st.size() == 0){
    minele = val;
    st.push(0);
    return;
}
int diff = val - minele;
st.push(diff);
if(val < minele){
    minele = val;
}
}
void pop(){
    int rem = st.top();
    st.pop();
    if(rem<0){
    int val = minele;
minele = minele - rem;
    } else {
        int val = minele + rem;
    }
}
int top(){
    int rem = st.top();
    if(rem<0){
        int val = minele;
        return val;
    } else {
        int val = minele + rem;
        return val;
    }
}
int getmin(){
    if(st.size() == 0){
        return -1;
    } else{
        return minele;
    }
}
};
int main() {
Minstack s1;
s1.push(10);
s1.push(12);
s1.push(14);
s1.push(8);
s1.push(16);
s1.push(18);
s1.push(20);
s1.push(6);
cout<<s1.getmin()<<endl;
s1.pop();
cout<<s1.top()<<endl;
cout<<s1.getmin();
return 0;
}