
#ifndef QUEUES_PROJ10_NODE_H
#define QUEUES_PROJ10_NODE_H

#include <stdexcept>

template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = NULL;
    }

    ~Node( ) {
        delete next;
    }
};

#endif //QUEUES_PROJ10_NODE_H
