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
    ~List();
    void add(const T &value);
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

template <typename T>
List<T>::~List()
{
    // struct Item *tmp;

    // while (head)
    // {
    //     tmp = head;
    //     head = head->next;
    //     delete tmp;
    // }
}

template <typename T>
void List<T>::add(const T &value)
{
    Item *n = new Item(value);
    Item *current = head;

    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        current->next = n;
    }

    size++;
}

template <typename T>
T List<T>::pop_front()
{
    Item *current = head;

    head = current->next;
    size--;

    T value = current->value;
    delete current;

    return value;
}

template <typename T>
T List<T>::get(uint8_t position)
{
    Item *current = head;

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
    return size;
};

#endif