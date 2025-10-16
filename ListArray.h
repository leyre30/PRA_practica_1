#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* data;
    int capacity;
    int currentSize;

public:
    ListArray(int cap = 10) : capacity(cap), currentSize(0) {
        data = new T[capacity];
    }

    void add(const T& item) override {
        if (currentSize < capacity) {
            data[currentSize++] = item;
        }
    }

    void remove(int index) override {
        if (index >= 0 && index < currentSize) {
            for (int i = index; i < currentSize - 1; ++i) {
                data[i] = data[i + 1];
            }
            --currentSize;
        }
    }

    T get(int index) const override {
        if (index >= 0 && index < currentSize) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    int size() const override {
        return currentSize;
    }

    ~ListArray() {
        delete[] data;
    }
};

#endif // LISTARRAY_H

