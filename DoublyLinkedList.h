#include "Node.h"
#include <iostream>

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    size_t size{};
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList() {clear();}

    void push_back(const T& value) {
        Node<T>* nd = new Node<T>(value);
        if (!tail) head = tail = nd;
        else {
            tail->next = nd;
            nd->prev = tail;
            tail = nd;
        }
        ++size;
    }
    void push_back(T&& value) {
        Node<T>* nd = new Node<T>(std::move(value));
        if (!tail) head = tail = nd;
        else {
            tail->next = nd;
            nd->prev = tail;
            tail = nd;
        }
        ++size;
    }

    void push_front(const T& value) {
        Node<T>* nd = new Node<T>(value);
        if (!head) head = tail = nd;
        else {
            nd->next = head;
            head->prev = nd;
            head = nd;
        }
        ++size;
    }
    void push_front(T&& value) {
        Node<T>* nd = new Node<T>(std::move(value));
        if (!head) head = tail = nd;
        else {
            nd->next = head;
            head->prev = nd;
            head = nd;
        }
        ++size;
    }

    size_t size() {
        return this->size;
    }

    void print() {
        if (!head) std::cout << "List is empty";
        else {
            Node<T>* tmp = head;
            do {
                std::cout << tmp->data << ' ';
                tmp = tmp->next;
            } while(tmp != nullptr);
            std::cout << "\n";
        }
    }
};

#endif //DOUBLE_LINKED_LIST