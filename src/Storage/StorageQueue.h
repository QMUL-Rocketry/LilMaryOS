#ifndef _STR_QUEUE_
#define _STR_QUEUE_

#include "StorageItem.h"

class QueueStorage {
public:
    // don't need to define a default constructor, already done here
    QueueStorage(int starting = 30);
    // make sure we delete dynamic object here!!!!!!!!
    ~QueueStorage();

    // Add to queue
    void add(StorageItem *item);

    // Remove oldest element
    StorageItem* pop();

    // Get size of queue
    int len();
private:
    // init with dynamic array that contains pointers
    StorageItem **arr;
    // resize if the queue gets to big
    void resize();
    // index to remove item
    int popI;
    // index to add item
    int addI;
    // apparent size
    int size;
    // actual size
    int length;
    // null safety

    // NOT IMPLEMENTED
    // bool null_safe();
};

#endif