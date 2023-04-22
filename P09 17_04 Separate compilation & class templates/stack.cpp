#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack() {
    size_ = 0;
    top_ = nullptr;
}

template <typename T>
Stack<T>::~Stack() {
    node<T>* current_to_delete = top_;
    while (current_to_delete != nullptr) {
        node<T>* next_to_delete = current_to_delete->next;
        delete current_to_delete;
        current_to_delete = next_to_delete;
    }
} 

template <typename T>
size_t Stack<T>::size() const {
    return size_;
}

template <typename T>
bool Stack<T>::peek(T& elem) const {
    if (size_ == 0) {
        return false;
    }
    elem = top_->value;
    return true;
}

template <typename T>
bool Stack<T>::pop(T& elem) {
    if (size_ == 0) {
        return false;
    }
    elem = top_->value;
    node<T>* new_top = top_->next;
    delete top_;
    top_ = new_top;
    size_--;
    return true;
}

template <typename T>
void Stack<T>::push(const T& elem) {
    node<T>* new_top = new node<T>;
    new_top->value = elem;
    new_top->next = top_;
    top_ = new_top;
    size_++;
}
