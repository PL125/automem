#include "stack.h"

template <typename T> 
Stack<T>::Stack() {
    this->head = nullptr;
    this->size = 0;
};

template <typename T> 
bool Stack<T>::push(T value) {
    top = Item(value, head);
};

template <typename T> 
void Stack<T>::pop() {
    Item* old = head;
    head = old->next;
    delete old;
};

template <typename T> 
bool Stack<T>::empty() {
    return head == nullptr;
};

template <typename T>
T Stack<T>::top() {
    return head->value;
};
