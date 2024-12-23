#pragma once
#include <iostream>
using namespace std;

template<typename type>
class Stack {
private:
    class Node {
    public:
        type data;
        Node* next;
        Node() : next(nullptr) {}
        Node(type data) : data(data), next(nullptr) {}
    };
    typedef Node* NodePointer;

    NodePointer mytop;
    int size;

public:
    Stack();
    ~Stack();
    bool empty() const;
    void push(type item);
    void pop();
    type& top();
    void display(ostream& out) const;
    void clear();
    
};





template<typename type>
Stack<type>::Stack() : mytop(nullptr), size(0) {}

template<typename type>
Stack<type>::~Stack() {
    clear();
}

template<typename type>
bool Stack<type>::empty() const {
    return mytop == nullptr;
}

template<typename type>
void Stack<type>::push(type item) {
    NodePointer ptr = new Node(item);
    if (!ptr) {
        throw std::bad_alloc();
    }
    ptr->next = mytop;
    mytop = ptr;
    size++;
  
}


template<typename type>
void Stack<type>::pop() {
    if (!empty()) {
        NodePointer ptr = mytop;
        mytop = mytop->next;
        delete ptr;
        size--;
    }
}

template<typename type>
type& Stack<type>::top() {
    if (!empty()) {
        return mytop->data;
    }
    throw runtime_error("Stack is empty");
}

template<typename type>
void Stack<type>::clear() {
    while (!empty()) {
        pop();
    }
}

template<typename type>
void Stack<type>::display(ostream& out) const {
    NodePointer ptr = mytop;
    while (ptr) {
        out << ptr->data << " ";
        ptr = ptr->next;
    }
    out << endl;
}












template class Stack<int>;
template class Stack<std::string>;