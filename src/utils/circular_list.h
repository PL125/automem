#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H 

template <typename T> 
class CircularList
{

    struct Item
    {
        T   value;
        Item* next;
        Item(T value, Item* next) {
            this->value = value;
            this->next = next;
        }
    };

    public:
        CircularList();
        // CircularList(T values[]);
        void add(T value);
        Item* head;
        
    private:
        int size;
};

#endif