#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

template <typename T>
class List
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
    List();
    // CircularList(T values[]);
    void add(T *value);
    Item *head;

private:
    int size;
};

template <typename T>
List<T>::List()
{
    this->head = nullptr;
};

template <typename T>
void List<T>::add(T *value)
{
    struct Item *n = (struct Item *)malloc(sizeof(struct Item));
    n->value = value;
    n->next = head;

    if (head->next == nullptr)
    {
        head->next = n;
    }
    else
    {
        Item *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;
    }
};

#endif