#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* ihead(Node* head,int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* iend(Node* head,int val) {
    if(head == NULL) return new Node(val);

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new Node(val);

    return head;
}

Node* ipos(Node* head, int val,int k) {
    Node* newNode = new Node(val);

    if(head == NULL) 
    {
        if(k == 1) return newNode;
        return head;
    }

    if(k == 1)
    {
        newNode->next = head;
        return newNode;
    }

    int c = 1;
    Node* temp = head;

    while(temp != NULL && c < k-1){
        temp = temp->next;
        c++;
    }

    if(temp == NULL) return head;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* ival(Node* head, int val,int x) {
    if(head == NULL) 
    {
        return NULL;
    }

    if(head->data == x) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while(temp->next != NULL){
        if(temp->next->data == x){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main() {

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    head = iend(head,2);
    head=ipos(head,2,3);   // inserts 2 at the end

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}