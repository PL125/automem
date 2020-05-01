#ifndef LIST_H
#define LIST_H

template <typename T>
class List
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
    List();
    void add(T *value);
    T* get(int position);

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
    struct Item *n = (struct Item *)malloc(sizeof(struct Item));
    n->value = value;
    n->next = nullptr;

    Item *current = this->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = n;
};

template <typename T>
T* List<T>::get(int position)
{
    Item *current = this->head; 
    for(int i=0; i<position+1; i++) {
        current = current->next;
    }

    return current->value;
};


#endif