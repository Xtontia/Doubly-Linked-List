#include <stdexcept>

#ifndef NODE
#define NODE

template <typename T>
struct Node {
    T data{};
    Node* next{};
    Node* prev{};
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    Node(T&& value) : data(std::move(value)), next(nullptr), prev(nullptr) {}
};

#endif //NODE