#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int calc(int a,int b, char c){
if(c == '+'){
    return a + b; 
} else if(c == '-'){
    return a-b;
} else if(c == '*'){
    return a*b;
} else {
    return a/b;
}
}
int prec(char c){
    if(c == '*' || c == '/'){
        return 1;
    } else {
        return 0;
    }
}
int infixevaluation(string s){
stack<int> operand;
stack<char> operators;
int i =0;
while(i<s.size()){
    if(s[i] >= '0' && s[i]<= '9'){
        int num = 0;
        while(i<s.size() && s[i]>='0' && s[i] <= '9'){
num = num*10 + (s[i] - '0');
i++;
        }
        operand.push(num);
        i--;
    } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
        while(operators.size()> 0 && prec(operators.top()) >= prec(s[i])){
            char oper = operators.top();
            operators.pop();
            int val2 = operand.top();
            operand.pop();
            int val1 = operand.top();
            operand.pop();
            int cal = calc(val1,val2,oper);
            operand.push(cal);
        }
        operators.push(s[i]);
    } else {
    }
    i++;
}
while(operators.size() > 0){
    char oper = operators.top();
    operators.pop();
    int val2 = operand.top();
operand.pop();
int val1 = operand.top();
operand.pop();
int cal = calc(val1,val2,oper);
operand.push(cal);
}
return operand.top();
}
int main() {
string s;
cin>>s;
int ans = infixevaluation(s);
cout<<ans;
return 0;
}