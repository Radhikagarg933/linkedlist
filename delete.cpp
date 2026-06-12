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

Node* dhead(Node* head) {
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* dend(Node* head) {
    if(head == NULL) return head;

    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

Node* dpos(Node* head, int k) {
    if(head == NULL) return head;

    if(k == 1) return dhead(head);

    Node* temp = head;
    Node* prev = NULL;
    int c = 1;

    while(temp != NULL && c < k) {
        prev = temp;
        temp = temp->next;
        c++;
    }

    if(temp != NULL) {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}

Node* dval(Node* head, int val) {
    if(head == NULL) return head;

    if(head->data == val) {
        return dhead(head);
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL) {
        if(temp->data == val) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
int main() {

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    head = dpos(head,2);   // deletes 2

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}