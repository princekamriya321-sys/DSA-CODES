#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class MinStack{
public:
stack<int> st;
stack<int> minSt;
void push(int val){
    st.push(val);
    if(minSt.empty() || val<= minSt.top()){
        minSt.push(val);
    } else {
        minSt.push(minSt.top());
    }
}
void pop(){
    if(!st.empty()){
        minSt.pop();
        st.pop();
    }
}
int top(){
    return st.top();
}
int getMin(){
    return minSt.top();
}
};
int main() {
MinStack ms;

    ms.push(5);
    ms.push(2);
    ms.push(7);
    ms.push(1);

    cout << "Top: " << ms.top() << endl;

    cout << "Minimum: " << ms.getMin() << endl;

    ms.pop();

    cout << "After Pop" << endl;

    cout << "Top: " << ms.top() << endl;

    cout << "Minimum: " << ms.getMin() << endl;

return 0;
}