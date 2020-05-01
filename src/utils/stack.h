#ifndef STACK_H
#define STACK_H 

template <typename T> 
class Stack
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
        Stack();
        bool push(T value);
        void pop();
        bool empty();
        T top();
        int size();
        
    private:
        Item* head;
};

#endif