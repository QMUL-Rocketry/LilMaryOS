#ifndef STORAGE
#define STORAGE

#include <SD.h>
#include "Queue.h"
#include "StorageItem.h"


// EPROMM handler should maybe be a different file. this should be limited

class StorageController {
public:

    StorageController();
    ~StorageController();

    // Adds the item to the queue in order to be saved later on
    bool push(StorageItem* item);

    // Pops the oldest item in the queue and saves it
    bool pop();

    // Performs an immediate save, bypassing the queue - not the same as a flush
    bool save(StorageItem* item);
private:
    // how many objects do we want to save per call 
    int rate;

    // REPLACE QUEUE WITH CUSTOM QUEUE SUPPORT
    QueueStorage items;
    // StorageItem items[100]; // ArrayList Queue --> fast, NEEDS MEMORY MANAGEMENT
    // Heap --> fast, good if we include priority, NEEDS MEMORY MANAGEMENT BUT MANAGEABLE
    // LinkedList --> easy but takes up quite a bit of memory, CANNOT REMOVE EASILY O(N) REMOVE TIME
};


#endif
