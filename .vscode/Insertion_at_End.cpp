#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void insertatbeginning(node*& head, int value){
    node* newnode = new node();
    newnode->data = value;
    newnode->next = head;
    head = newnode;
};

void insertatend(node*& head, int value){
    node* newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;
    if(head == nullptr){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
}

int main() {
    node* head = new node();
    node* n1 = new node();
    node* n2 = new node();
    node* n3 = new node();

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = nullptr;
    head = n1;
    
    insertatbeginning(head, 5);
    insertatend(head, 40);
    node* temp = head;
    
    while(temp != 0){
        cout << temp->data << " -> ";
        temp = temp->next;
    }


    cout << "NULL";
    return 0;
}