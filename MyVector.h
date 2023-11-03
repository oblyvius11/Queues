
#ifndef QUEUES_PROJ10_MYVECTOR_H
#define QUEUES_PROJ10_MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include "proj10-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    MyVector() : data(nullptr), size(0), capacity(0) {}
    ~MyVector() {
        if (data) {
            delete[] data;
        }
    }
    MyVector(const MyVector<T>& other) : data(nullptr), size(0), capacity(0) {
        for (int i = 0; i < other.getSize(); i++) {
            pushBack(other[i]);
        }
    }
    MyVector<T>& operator=(const MyVector<T>& other) {
        if (&other == this) {
            return *this;
        }

        erase();
        for (int i = 0; i < other.getSize(); i++) {
            pushBack(other[i]);
        }

        return *this;
    }
    MyVector<T>& pushFront(T item) {
        if (size == capacity) {
            grow();
        }
        shiftRight();
        data[0] = item;
        size++;
        return *this;
    }
    MyVector<T>& pushBack(T item) {
        if (size == capacity) {
            grow();
        }
        data[size] = item;
        size++;
        return *this;
    }
    MyVector<T>& popFront(T& item) {
        if (isEmpty()) {
            throw BADINDEX();
        }
        item = data[0];
        shiftLeft();
        size--;
        return *this;
    }
    MyVector<T>& popBack(T& item) {
        if (isEmpty()) {
            throw BADINDEX();
        }
        item = data[size - 1];
        size--;
        return *this;
    }
    T front() {
        if (isEmpty()) {
            throw BADINDEX();
        }
        return data[0];
    }
    T back() {
        if (isEmpty()) {
            throw BADINDEX();
        }
        return data[size - 1];
    }
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw BADINDEX();
        }
        return data[index];
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void erase() {
        if (data) {
            delete[] data;
            data = nullptr;
        }
        size = 0;
        capacity = 0;
    }

private:
    T* data;
    int size;
    int capacity;

    void grow() {
        int newCapacity = capacity * 2 + 1;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        if (data) {
            delete[] data;
        }
        data = newData;

    }
    void shiftRight() {
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
    }
    void shiftLeft() {
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
    }
};

#endif //QUEUES_PROJ10_MYVECTOR_H
