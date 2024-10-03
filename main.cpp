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
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    head = insertNode(head, entry, 10000);
    output(head);

    deleteList(head);
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

Node* addNodeToFront(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

Node* addNodeToTail(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        return newNode;
    }

    Node *current = head;
    while (current->next) {

