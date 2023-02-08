#ifndef STORAGE
#define STORAGE

#include <SD.h>
#include "StorageItem.h"


// EPROMM handler should maybe be a different file. this should be limited

class StorageController {
public:

    StorageController();
    ~StorageController();

    // Adds the item to the queue in order to be saved later on
    bool add(StorageItem item);

    // Pops the oldest item in the queue and saves it
    bool pop();

    // Performs an immediate save, bypassing the queue
    bool save(StorageItem item);
private:
    // how many objects do we want to save per call 
    int rate;

    // StorageItem items[100]; // ArrayList Queue --> fast, NEEDS MEMORY MANAGEMENT
    // Heap --> fast, good if we include priority, NEEDS MEMORY MANAGEMENT BUT MANAGEABLE
    // LinkedList --> easy but takes up quite a bit of memory, CANNOT REMOVE EASILY O(N) REMOVE TIME
};


#endif
