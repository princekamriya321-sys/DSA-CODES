#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* mid(Node* h1){
    Node* s = h1;
    Node* f = h1;
    while(f->next != nullptr && f->next->next != nullptr){
        s = s->next;
        f = f->next->next;
    }
    return s;
}
Node* Merge(Node* n1,Node* n2){
    Node* t = nullptr;
    Node* ans = nullptr;
    if(n1->data < n2->data){
        t = n1;
        ans = n1;
        n1 = n1->next;
    } else {
        t = n2; 
        ans = n2; 
        n2 = n2->next;
    }
    while(n1 != nullptr && n2 != nullptr){
        if(n1->data < n2->data){
            t->next = n1;
            n1 = n1->next;
            t = t->next;
        } else {
            t->next = n2;
            n2 = n2->next;
            t = t->next;
        }
    }
    while(n1 != nullptr){
        t->next = n1;
        n1 =n1->next;
        t = t->next;
    }
    while(n2 != nullptr){
        t->next = n2;
        n2 = n2->next;
        t = t->next;
    }
    return ans;
}
Node* Mergesort(Node* h1){
    if(h1->next == nullptr) return h1;
    Node* m = mid(h1);
    Node* h2 = m->next;
    m->next = nullptr;
    Node* t1 = Mergesort(h1);
    Node* t2 = Mergesort(h2);
    Node* t3 = Merge(t1,t2);
    return t3;
}
int main(){

    // Unsorted Linked List
    Node* head = new Node(14);
    head->next = new Node(3);
    head->next->next = new Node(19);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(11);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    // Write your Merge Sort code here
Node* temp = Mergesort(head);
cout<<"Sorted List: ";
printList(temp);
    return 0;
}