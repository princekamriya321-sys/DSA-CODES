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
Node* Intersectionoflinkedlist(Node* head1,Node* head2){
    int l1 = 0;
    int l2 = 0;
    Node* t1 = head1;
    while(t1!= nullptr){
        l1++;
        t1 =t1->next;
    }
    Node* t2 = head2;
    while(t2 != nullptr){
        l2++;
        t2 = t2->next;
    }
    if(l2 > l1){
        int l3 = l2 -l1;
        Node* temp = head2;
        while(l3 != 0){
            l3--;
            temp = temp->next;
        }
        t1 = head1;
        while(temp != nullptr && t1 != nullptr){
            if(temp == t1) return temp;
            t1 = t1->next;
            temp = temp->next;
        }
    } else {
        int l3 = l1-l2;
        Node* temp = head1;
        while(l3 != 0){
            l3--;
            temp = temp->next;
        }
        t2 = head2;
        while(temp != nullptr && t2 != nullptr){
            if(temp == t2) return temp;
            t2 = t2->next;
            temp = temp->next;
        }
    }
    return nullptr;
}
int main(){

    // Common Part (Intersection starts here)
    Node* common = new Node(4);
    common->next = new Node(6);
    common->next->next = new Node(2);

    // List 1: 3 -> 1 -> 4 -> 6 -> 2
    Node* head1 = new Node(3);
    head1->next = new Node(1);
    head1->next->next = common;

    // List 2: 1 -> 2 -> 4 -> 5 -> 4 -> 6 -> 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(5);
    head2->next->next->next->next = common;

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* temp = Intersectionoflinkedlist(head1,head2);

if(temp != nullptr){
    cout <<"Intersection Value: "<<temp->data << endl;
}
else{
    cout << "No Intersection" << endl;
}
    return 0;
}