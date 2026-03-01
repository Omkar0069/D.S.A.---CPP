#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
int main(){
    node* head = new node;
    node* n1 = new node;
    node* n2 = new node;
    node* n3 = new node;

    head->data = 10;
    n1->data = 20;
    n2->data = 30;
    n3->data = 40;

    head->prev = nullptr;
    n1->prev = head;
    n2->prev = n1;
    n3->prev = n2;

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    node* temp = head;

    node* newnode = new node();
    newnode->data = 50;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = nullptr;
    

    temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

