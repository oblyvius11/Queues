

#ifndef QUEUES_PROJ10_MYLIST_H
#define QUEUES_PROJ10_MYLIST_H

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"

template <class T>
class MyList : public ContainerIfc<T> {
public:
    MyList() : head(nullptr), tail(nullptr), size(0) {}

    ~MyList() {
        clear();
    }

    MyList(const MyList& other) : MyList() {
        for (Node<T>* node = other.head; node != nullptr; node = node->next) {
            pushBack(node->data);
        }
    }

    MyList<T>& operator=(const MyList& other) {
        clear();
        for (Node<T>* node = other.head; node != nullptr; node = node->next) {
            pushBack(node->data);
        }
        return *this;
    }

    MyList<T>& pushFront(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
        return *this;
    }

    MyList<T>& pushBack(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return *this;
    }

    MyList<T>& popFront(T& data) {
        if (isEmpty()) {
            throw BADINDEX();
        }
        Node<T>* oldHead = head;
        data = oldHead->data;
        head = head->next;
        oldHead->next = nullptr;
        delete oldHead;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
        return *this;
    }

    MyList<T>& popBack(T& data) {
        if (isEmpty()) {
            throw BADINDEX();
        }
        if (head == tail) {
            return popFront(data);
        }
        Node<T>* prev = nullptr;
        for (Node<T>* node = head; node != tail; node = node->next) {
            prev = node;
        }
        data = tail->data;
        prev->next = nullptr;
        delete tail;
        tail = prev;
        size--;
        return *this;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    T front() {
        if (isEmpty()) {
            throw BADINDEX();
        }
        return head->data;
    }
    T back() {
        if (isEmpty()) {
            throw BADINDEX();
        }
        return tail->data;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw BADINDEX();
        }
        Node<T>* node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->data;
    }

    void erase() {
        clear();
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    void clear() {
        delete head;
        head = tail = nullptr;
        size = 0;
    }
};

#endif //QUEUES_PROJ10_MYLIST_H
