#ifndef LIST_H
#define LIST_H

#include <stdint.h>

template <typename T>
class List
{

    class Item
    {
    public:
        T *value;
        Item *next;
        Item(T *value)
        {
            this->value = value;
            this->next = nullptr;
        }
    };

public:
    List();
    void add(T *value);
    T get(uint8_t position);
    uint8_t length();

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

template <typename T>
void List<T>::add(T *value)
{
    Item *n = new Item(value);
    Item *current = this->head;

    if (this->head == nullptr)
    {
        this->head = n;
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
    }

    this->size++;
}

template <typename T>
T List<T>::get(uint8_t position)
{
    Item *current = this->head;

    int count = 0;
    while (current != nullptr)  
    {
        if (count == position)  
            return *current->value;
        count++;
        current = current->next;
    }
};

template <typename T>
uint8_t List<T>::length()
{
    return this->size;
};

#endif