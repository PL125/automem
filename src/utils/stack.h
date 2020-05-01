#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{

    struct Item
    {
        T value;
        Item *next;
        Item(T value, Item *next)
        {
            this->value = value;
            this->next = next;
        }
    };

public:
    Stack();
    void push(T value);
    void pop();
    bool empty();
    T top();

private:
    Item *head;
};

template <typename T>
Stack<T>::Stack()
{
    this->head = nullptr;
    this->size = 0;
};

template <typename T>
void Stack<T>::push(T value)
{
    head = Item(value, head);
};

template <typename T>
void Stack<T>::pop()
{
    Item *old = head;
    head = old->next;
    delete old;
};

template <typename T>
bool Stack<T>::empty()
{
    return head == nullptr;
};

template <typename T>
T Stack<T>::top()
{
    return head->value;
};

#endif