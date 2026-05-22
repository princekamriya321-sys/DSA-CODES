//LIFO -> Last in first out 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
cout<<st.top()<<endl;
st.pop();
cout<<st.top()<<endl;
cout<<st.size()<<endl;
cout<<st.empty()<<endl;
return 0;
}