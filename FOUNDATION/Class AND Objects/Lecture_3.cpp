#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Student{

public:
    string name;
    int age;
Student(string n, int a){
    name = n;
    age = a;
}
void display(){
    cout<<name<<" "<<age<<endl;
}
};

int main(){

    Student s1("Prince",20);
   s1.display();
    return 0;
}