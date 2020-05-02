#ifndef LIST_H
#define LIST_H

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
    T get(int position);

private:
    Item *head;
};

template <typename T>
List<T>::List()
{
    this->head = nullptr;
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
};

template <typename T>
T List<T>::get(int position)
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

#endif