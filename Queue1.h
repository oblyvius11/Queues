
#ifndef QUEUES_PROJ10_QUEUE1_H
#define QUEUES_PROJ10_QUEUE1_H

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
    void enqueue(T item) {
        MyVector::pushBack(item);
    }
    void dequeue(T& item) {
        popFront(item);
    }
};

#endif //QUEUES_PROJ10_QUEUE1_H
