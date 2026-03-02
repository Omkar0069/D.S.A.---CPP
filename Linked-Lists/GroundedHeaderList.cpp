#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int main(){
    node* head = new node();
    head->data = 0;
    head->next = nullptr;

    node* n1 = new node();
    node* n2 = new node();
    node* n3 = new node();

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    node* temp = head->next;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
}