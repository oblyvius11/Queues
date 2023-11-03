

#ifndef QUEUES_PROJ10_QUEUE3_H_H
#define QUEUES_PROJ10_QUEUE3_H_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
    void enqueue(T data) {
        this->pushBack(data);
    }

    void dequeue(T& data) {
        this->popFront(data);
    }
};

#endif //QUEUES_PROJ10_QUEUE3_H_H
