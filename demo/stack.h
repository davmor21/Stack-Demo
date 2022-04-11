#ifndef STACK_H
#define STACK_H

class Stack {

private:
    // structure for a Node
    struct Node {
        int value;
        
        struct Node* next;  // pointer to another node
        
    };
    int size;
    Node* top; // pointer to the top of the stack


public:
    Stack() {
        top = nullptr;
        size= 0;
    }

    // Destructor
    ~Stack();

    void printStack() const;
    void push(int);
    void pop(int&);
    void printSize();
    void peek();
    void clearStack();
    void findItem(int);
};
#endif
