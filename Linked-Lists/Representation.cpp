#include<iostream>
using namespace std;
struct node{
    int coeff;
    int exp;
    node* next;
};
int main(){
    node* head = new node();
    node* n1 = new node();
    node* n2 = new node();
    node* n3 = new node();

    head->coeff = 5;
    head->exp = 3;
    head->next = n1;

    n1->coeff = 4;
    n1->exp = 2;
    n1->next = n2;

    n2->coeff = 3;
    n2->exp = 1;
    n2->next = n3;

    n3->coeff = 2;
    n3->exp = 0;
    n3->next = nullptr;

    node* temp = head;
    while(temp != nullptr){
        if(temp->exp == 0){
            cout << temp->coeff << " ";
}   else if(temp->exp == 1){
            cout << temp->coeff << "x ";
        }else{
            cout << temp->coeff << "x^" << temp->exp << " ";
        }
        if(temp->next != nullptr && temp->next->coeff > 0){
            cout << "+ ";
        }
        temp = temp->next;
    }
    cout << endl;

}
