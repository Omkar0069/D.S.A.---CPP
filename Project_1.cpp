#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct node {
    string ip;
    string attacktype;
    string timestamp;    // ✅ renamed
    int severity;
    node* next;
    node* prev;
};

string gettime(){
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
};

node* createLog(string ip, string attackType, int severity){
    node* newNode = new node();
    newNode->ip = ip;
    newNode->attacktype = attackType;
    newNode->severity = severity;
    newNode->timestamp = gettime();  // ✅ renamed
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
};

void logAttack(node* &head, string ip, string attackType, int severity){
    node* newLog = createLog(ip, attackType, severity);
    if(head == nullptr){
        head = newLog;
        return;
    }
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newLog;
    newLog->prev = temp;
}

void viewLogs(node* head){
    if(head == nullptr){
        cout << "\n❌ No attacks logged yet!" << endl;
        return;
    }
    cout << "\n===== ALL ATTACK LOGS =====" << endl;
    node* temp = head;
    int count = 1;
    while(temp != nullptr){
        cout << "[" << count << "] ";
        cout << "IP: " << temp->ip << " | ";
        cout << "Attack: " << temp->attacktype << " | ";
        cout << "Severity: " << temp->severity << "/5 | ";
        cout << "Time: " << temp->timestamp << endl;  // ✅ renamed
        temp = temp->next;
        count++;
    }
    cout << "===========================" << endl;
}

int main(){
    node* head = nullptr;
    int choice;
    do {
        cout << "\n====== ATTACK LOG TRACKER ======" << endl;
        cout << "1. Log new attack" << endl;
        cout << "2. View all logs" << endl;
        cout << "0. Exit" << endl;
        cout << "================================" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 1){
            string ip, attackType;
            int severity;
            cout << "Enter IP address: ";
            cin >> ip;
            cout << "Enter attack type (e.g. SSH_Brute_Force): ";
            cin >> attackType;
            cout << "Enter severity (1-5): ";
            cin >> severity;
            logAttack(head, ip, attackType, severity);
            cout << "✅ Attack logged successfully!" << endl;
        }
        else if(choice == 2){
            viewLogs(head);
        }
    } while(choice != 0);
    cout << "Exiting..." << endl;
    return 0;
}