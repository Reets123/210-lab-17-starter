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
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteNode(Node *head, int position) {
    if (!head || position < 1) return head;  // Invalid position

    Node *current = head;
    if (position == 1) {  // Deleting the head
        head = current->next;
        delete current;
        return head;
    }

    Node *prev = nullptr;
    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }
    
    if (current) { // Node to be deleted found
        prev->next = current->next;
        delete current;
    }
    
    return head;
}

Node* insertNode(Node *head, int position, float value) {
    if (position < 1) return head;

    if (position == 1) {  // Insert at the front
        return addNodeToFront(head, value);
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    Node *current = head;
    Node *prev = nullptr;
    
    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    // Insert new node between prev and current
    if (prev) {
        newNode->next = current;
        prev->next = newNode;
    }
    
    return head;
}

void delete

