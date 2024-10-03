// Lab 17: Modularize the Linked List Code
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototypes
void output(Node *);
Node* addNodeToFront(Node *, float);
Node* addNodeToTail(Node *, float);
Node* deleteNode(Node *, int);
Node* insertNode(Node *, int, float);
void deleteList(Node *&);


int main() {
    Node *head = nullptr;
    
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addNodeToFront(head, tmp_val);   
    }
    output(head);

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    head = deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}