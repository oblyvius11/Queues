
#ifndef QUEUES_PROJ10_QUEUE2_H
#define QUEUES_PROJ10_QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front; // front index of the queue
    int rear; // rear index of the queue
public:
    Queue2() : front(0), rear(0) {}
    void enqueue(T item) {
        this->pushBack(item);
        rear++;
    }
    void dequeue(T& item) {
        if (this->isEmpty()) {
            throw BADINDEX();
        }
        item = this->front();
        this->popFront(item);
        front++;
    }
};

#endif //QUEUES_PROJ10_QUEUE2_H
