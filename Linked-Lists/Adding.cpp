#include<iostream>
using namespace std;
struct node{
    int coeff;
    int exp;
    node* next;
};

node* createnode(int coeff, int exp){
    node* newnode = new node();
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = nullptr;
    return newnode;
};

void print(node* head){
    node* temp = head;
    while (temp != nullptr){
        if(temp->exp == 0){
            cout << temp->coeff << " ";
        } else if(temp->exp == 1){
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
};

node* addpolynomials(node* p1, node* p2){
    node* result = nullptr;
    node* tail = nullptr;

    while(p1 != nullptr && p2 != nullptr){
        node* newnode;

        if(p1->exp > p2->exp){
            newnode = createnode(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        else if(p2->exp > p1->exp){
            newnode = createnode(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        else{
            newnode = createnode(p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        if(result == nullptr){
            result = newnode;
            tail = newnode;
        }
        
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    while(p1 != nullptr){
       tail->next = createnode(p1->coeff, p1->exp);
       tail = tail->next;
       p1 = p1->next;
    }
    while (p2 != nullptr)
    {
        tail->next = createnode(p2->coeff, p2->exp);
        tail = tail->next;
        p2 = p2->next;
    }
    
    return result;
}

int main(){
    node* p1 = createnode(5, 3);
    p1->next = createnode(4, 2);
    p1->next->next = createnode(3, 1);

    node* p2 = createnode(2, 3);
    p2->next = createnode(1, 1);
    p2->next->next = createnode(6, 0);

    cout << "Polynomial 1: ";
    print(p1);
    cout << "Polynomial 2: ";
    print(p2);

    node* result = addpolynomials(p1, p2);
    cout << "Sum: ";
    print(result);

    return 0;
}