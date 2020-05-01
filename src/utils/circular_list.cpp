#include "circular_list.h"

template <typename T> 
CircularList<T>::CircularList() {
    this->head = nullptr;
};

// template <typename T> 
// CircularList<T>::CircularList(T values[]) {
//     this->head = volues[0];
// };

template <typename T> 
void CircularList<T>::add(T value) {
    struct Item *n = (struct Item *)malloc(sizeof(struct Item));
    struct Item *ptr = head; 

    n->value = value;
    n->next = head;
    if(head != nullptr) {
        while (ptr->next != head) 
            ptr = ptr->next; 
        ptr->next = n; 
    } else {
        n->next =  n;
        head = n;
    }
};