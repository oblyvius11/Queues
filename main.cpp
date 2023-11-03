#include <iostream>
#include <cstdlib>
#include <ctime>
#include "proj10-Queue1.h"

using namespace std;

int main() {
    srand(time(NULL));
    Queue1<int> queue;
    for (int i = 0; i < 100; i++) {
        queue.enqueue(rand());
    }

    time_t start_time = time(NULL);
    int item;
    while (!queue.isEmpty()) {
        queue.dequeue(item);
    }
    time_t end_time = time(NULL);
    cout << "Time taken to dequeue all items: " << end_time - start_time << " seconds." << endl;

    return 0;
}
