#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;
    int currentSize;

public:
    ListLinked() : head(nullptr), currentSize(0) {}

    void add(const T& item) override {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = head;
        head = newNode;
        ++currentSize;
    }

    void remove(int index) override {
        if (index < 0 || index >= currentSize) return;

        Node<T>* current = head;
        if (index == 0) {
            head = current->next;
            delete current;
        } else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < index; ++i) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
        }
        --currentSize;
    }

    T get(int index) const override {
        if (index < 0 || index >= currentSize) throw std::out_of_range("Index out of range");

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int size() const override {
        return currentSize;
    }

    ~ListLinked() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif // LISTLINKED_H

