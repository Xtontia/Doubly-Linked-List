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

    void push_back(const T& value) {
        Node<T>* nd = new Node<T>(value);
        if (!tail) head = tail = nd;
        else {
            tail->next = nd;
            nd->prev = tail;
            tail - nd;
        }
        ++size;
    }
    void push_back(T&& value) {
        Node<T>* nd = new Node<t>(std::move(value));
        if (!tail) head = tail = nd;
        else {
            tail->next = nd;
            nd->prev = tail;
            tail = nd;
        }
        ++size;
    }

};

#endif //DOUBLE_LINKED_LIST