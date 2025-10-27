#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    size_t size{};

    void copyFrom(const DoublyLinkedList& other) {
        Node<T>* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {clear();}

    DoublyLinkedList(const DoublyLinkedList& other)
        : head(nullptr), tail(nullptr), size(0) {
        copyFrom(other);
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

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

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete(current);
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    size_t get_size() {
        return this->size;
    }

    void print() {
        if (!head) {
            std::cout << "List is empty";
            return;
        }
        else {
            Node<T>* tmp = head;
            while (tmp) {
                std::cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            std::cout << "\n";
        }
    }
};

#endif //DOUBLY_LINKED_LIST