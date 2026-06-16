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
Node* Merge(Node* n1,Node* n2){
    Node* ans = nullptr;
    Node* t = nullptr;
    if(n1->data < n2->data){
        ans = n1;
        t = n1;
        n1 = n1->next;
    } else {
        ans = n2;
        t = n2;
        n2 = n2->next;
    }
    while(n1 != nullptr && n2 != nullptr){
        if(n1->data < n2->data){
            t->next = n1;
            t = t->next;
            n1 = n1->next;
        } else {
            t->next = n2;
            t = t->next;
            n2 = n2->next;
        }
    }
    while(n1 != nullptr){
        t->next = n1;
        t = t->next;
        n1 = n1->next;
    }
    while(n2 != nullptr){
        t->next = n2;
        t = t->next;
        n2 = n2->next;
    }
    return ans;
}
int main(){

    // First Sorted Linked List
    Node* head1 = new Node(2);
    head1->next = new Node(5);
    head1->next->next = new Node(10);
    head1->next->next->next = new Node(14);
    head1->next->next->next->next = new Node(19);

    // Second Sorted Linked List
    Node* head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(11);
    head2->next->next->next->next = new Node(12);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    // Write your merge code here
Node* temp = Merge(head1,head2);
cout<<"Final List: ";
printList(temp);
    return 0;
}