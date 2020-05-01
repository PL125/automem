#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template <typename T>
class CircularList
{

    struct Item
    {
        T *value;
        Item *next;
        Item(T value, Item *next)
        {
            this->value = value;
            this->next = next;
        }
    };

public:
    CircularList();
    // CircularList(T values[]);
    void add(T *value);
    Item *head;

private:
    int size;
};

template <typename T>
CircularList<T>::CircularList()
{
    this->head = nullptr;
};

template <typename T>
void CircularList<T>::add(T *value)
{
    struct Item *n = (struct Item *)malloc(sizeof(struct Item));
    struct Item *ptr = head;

    n->value = value;
    n->next = head;
    if (head != nullptr)
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = n;
    }
    else
    {
        n->next = n;
        head = n;
    }
};

#endif