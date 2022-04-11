#include <iostream>
#include "Stack.h"
using namespace std;

/* printStack traverses the stack and displays the
** value of each node
*/
void Stack::printStack() const {
    Node* nodePtr;  // Node to traverse the stack

    // Start at the beginnging of the stack
    nodePtr = top;

    // Traverse the stack until nodePtr is at the end
    while (nodePtr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;  //advance to the next node
    }
}

/* push() creates a new Node and then
** inserts the new Node at the top of the stack
*/
void Stack::push(int num) {

    Node* newNode;  // pointer for node to push
    
    // Creat a new Node and store the value
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    if (!top) {          //if the stack is empty, the new Node becomes the top
        top = newNode;
        size++;
    }
    else {               //otherwise, insert new node at the front
        newNode->next = top;
        top = newNode;
        size++;
    }
}

/* pop() removes the top value and
** stores the value in the argument
*/
void Stack::pop(int &num) {
    Node* nodePtr;

    if (!top) {
        return;
    }
    else {
        num = top->value;
        nodePtr = top->next;
        delete top;
        top = nodePtr;
        size--;
    }
}

/* The destructor traverses the stack and deletes each node
*/
Stack::~Stack() {
    Node* nodePtr;   // Node for travrsing the stack
    Node* nextNode;  // Node for tracking the next node in the stack

    //Set the traversing pointer to the top of the stack
    nodePtr = top;

    // Traverse the stack until at the end 
    while (nodePtr) {
        nextNode = nodePtr->next;  //Save pointer to next Node 
        delete nodePtr;            //Delete the current node
        size--;
        nodePtr = nextNode;        //Move traversing pointer to the next Node
    }
}
void Stack::printSize() {
    cout << size << endl;
}
void Stack::peek() {
    cout << top->value << endl;
}
void Stack:: clearStack() { //same thing as destructor
    Node* nodePtr;   // Node for travrsing the stack
    Node* nextNode;  // Node for tracking the next node in the stack

    //Set the traversing pointer to the top of the stack
    nodePtr = top;

    // Traverse the stack until at the end 
    while (nodePtr) {
        nextNode = nodePtr->next;  //Save pointer to next Node 
        delete nodePtr;            //Delete the current node
        size--;
        nodePtr = nextNode;        //Move traversing pointer to the next Node
    }
}
void Stack::findItem(int item) { // find an item in the list and return the position
    Node* nodePtr = top;  // start at first node
    Node* previous = top; // start at first node
    int counter = 1;
    if (!top) { // if there is no list
        cout << "No items in list" << endl;
        return;
    }
    else if (top->value == item) { // if it is the first item in the list
        cout << "Number was at position " << counter << endl;
    }
    else {
        while (nodePtr != nullptr && nodePtr->value != item) { // increase the counter to match the position until the item is found
            counter++;
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr == nullptr) {
            cout << "Item not found" << endl;
        }
        else if (nodePtr->value == item) {
            cout << "Number was at position " << counter << endl; // after counter is finalized, return the counter as the position
        }
        else {
            cout << "Item not found" << endl;
        }
    }
}
