#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{

    struct Item
    {
        T *value;
        Item *next;
        Item(T *value, Item *next)
        {
            this->value = value;
            this->next = next;
        }
    };

public:
    Stack();
    void push(T *value);
    T* pop();
    T* top();
    bool empty();

private:
    Item *head;
};

template <typename T>
Stack<T>::Stack()
{
    this->head = nullptr;
};

template <typename T>
void Stack<T>::push(T *value)
{
    head = new Item(value, head);
};

template <typename T>
T* Stack<T>::pop()
{
    Item *old = head;
    head = old->next;

    return old->value;
};

template <typename T>
T* Stack<T>::top()
{
    return head->value;
};

#endif