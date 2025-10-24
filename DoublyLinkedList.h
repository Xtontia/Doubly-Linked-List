#include "Node.h"

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    size_t size{};
public:
    DoubleLinkedList() : head(nullptr), taill(nullptr), size(0) {}
    ~DoubleLinkedList() {clear();}

    void push_back()

};

#endif //DOUBLE_LINKED_LIST