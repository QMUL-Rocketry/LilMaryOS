#ifndef STORAGE
#define STORAGE

#include <SD.h>
#include "Queue.h"
#include "StorageItem.h"
#include "EPROM.h"

// EPROMM handler should maybe be a different file. this should be limited

class StorageController {
public:
    StorageController();
    ~StorageController();

    // Adds the item to the queue in order to be saved later on
    bool push(StorageItem* item);

    // Pops the oldest item in the queue and saves it
    // WARNING: NULL SAFETY
    StorageItem* pop();

    // Performs an immediate save, bypassing the queue - not the same as a flush
    // WARNING: IMPLEMENT NULL SAFETY CHECK
    bool save(StorageItem* item);
private:
    // how many objects do we want to save per call 
    int rate;

    // Might change to a multi queue system, where each data type has it own
    // queue. this will be great performance wise? but not space - leave for now
    // great for the flush functionality
    QueueStorage items;
    // StorageItem items[100]; // ArrayList Queue --> fast, NEEDS MEMORY MANAGEMENT
    // Heap --> fast, good if we include priority, NEEDS MEMORY MANAGEMENT BUT MANAGEABLE
    // LinkedList --> easy but takes up quite a bit of memory, CANNOT REMOVE EASILY O(N) REMOVE TIME

    // idek what we are gonna use it for, extra storage, useful for long term
    // mainly for reads
    EPROMController eprom;
    // Store any bytes?
    enum eprom_map{};

    void getType(StorageItem *item);
};



#endif
