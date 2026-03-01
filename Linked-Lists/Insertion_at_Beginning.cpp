#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
int main() {
   node* head = new node();
   node* n1 = new node();
   node* n2 = new node();
   node* n3 = new node();

   head->data = 10;
   head->next = n1;
    n1->data = 20;
    n1->next = n2;
    n2->data = 30;
    n2->next = n3;
    n3->data = 40;
    n3->next = nullptr;

    node* newnode = new node();
    newnode->data = 5;
    newnode->next = head;
    head = newnode;


    node* temp = head;
   while(temp != 0){
    cout << temp->data << " -> ";
    temp = temp->next;
   }
   cout << "NULL";
    return 0;
}