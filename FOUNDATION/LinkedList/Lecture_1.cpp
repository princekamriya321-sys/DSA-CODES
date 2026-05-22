#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {

public:

    int data;
    Node* next;
};

int main() {

    Node* first = new Node();

    first->data = 10;
    first->next = NULL;

    Node* second = new Node();

    second->data = 20;
    second->next = NULL;

    first->next = second;

    cout << first->data << endl;
    cout << first->next->data << endl;

    return 0;
}