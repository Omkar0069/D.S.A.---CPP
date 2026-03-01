#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
int main(){
    node* head = new node();

    node* n1 = new node;
    node* n2 = new node;
    node* n3 = new node;        
    head->data = 10;
    head->prev = nullptr;
    head->next = n1;
    n1->data = 20;
    n1->prev = head;
    n1->next = n2;
    n2->data = 30;
    n2->prev = n1;
    n2->next = n3;
    n3->data = 40;
    n3->prev = n2;
    n3->next = nullptr;

    node* temp = head;
    head = temp->next;

    head = temp->next;
    temp->next->prev = nullptr;
    delete temp; 
    
    temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    return 0;
}