#ifndef LIST_H
#define LIST_H

#include <stdint.h>

template <typename T>
class List
{

    class Item
    {
    public:
        T value;
        Item *next;
        Item(T value)
        {
            this->value = value;
            this->next = nullptr;
        }
    };

public:
    List();
    // ~List();
    void add(T value);
    T pop_front();
    T get(uint8_t position);
    int length();

private:
    Item *head;
    uint8_t size;
};

template <typename T>
List<T>::List()
{
    this->head = nullptr;
    this->size = 0;
};

// template <typename T>
// List<T>::~List()
// {
//     Item *current = this->head;
//     while (current)
//     {
//         Item *next = current->next;
//         delete current;
//         current = next;
//     }
// }

template <typename T>
void List<T>::add(T value)
{
    Item *n = new Item(value);
    Item *current = this->head;

    if (this->head == nullptr)
    {
        this->head = n;
    }
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        current->next = n;
    }

    this->size++;
}

template <typename T>
T List<T>::pop_front()
{
    Item *current = this->head;

    this->head = current->next;
    this->size--;

    T value = current->value;
    delete current;

    return value;
}

template <typename T>
T List<T>::get(uint8_t position)
{
    Item *current = this->head;

    int count = 0;
    while (current)
    {
        if (count == position)
            return current->value;
        count++;
        current = current->next;
    }
};

template <typename T>
int List<T>::length()
{
    return this->size;
};

#endif