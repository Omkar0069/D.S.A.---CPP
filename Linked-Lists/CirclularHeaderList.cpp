#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;

};
int main(){
    node* head = new node();
    head->data = 0;
    head->prev = nullptr;
    head->next = nullptr;

    node* n1 = new node;
    node* n2 = new node;
    node* n3 = new node;

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    head->prev = n3;
    n1->prev = head;
    n2->prev = n1;
    n3->prev = n2;

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = head;

    node* temp = head->next;
    do{
        cout << temp->data << " <-> ";
        temp = temp->next;
    }while(temp != head);
cout << "Back to head: " << temp->data << endl;

    node* tail = n3;
    do{
        cout << tail->data << " <-> ";
        tail = tail->prev;
    }while(tail != n3);
cout << "Back to tail: " << tail->data << endl;

return 0;
}