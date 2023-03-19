#ifndef _STORAGE_
#define _STORAGE_

#include <SD.h>
#include "StorageQueue.h"
#include "StorageItem.h"
#include "EPROM.h"
#include "globals.h"
#include "../Scheduler/RunMember.h"

// EPROMM handler should maybe be a different file. this should be limited

class StorageController : public RunMember {
// class StorageController {
public:
    StorageController();
    ~StorageController();

    // controller logic to save the files, to be attached to the sceduler
    // need to inherit RunMember
    void run();

    // Adds the item to the queue in order to be saved later on
    // void push(StorageItem* item);
    void add(StorageItem* item);
    
    // Pops the oldest item in the queue and saves it
    // WARNING: NULL SAFETY
    // bool pop();
    bool save();

    // Performs an immediate save, bypassing the queue - not the same as a flush
    // WARNING: IMPLEMENT NULL SAFETY CHECK
    // bool save(StorageItem* item);
    bool forceSave(StorageItem* item);

    // saves all items currently in the queue
    void flush();

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

    bool write(char loc[], char data[]);

    char* getType(SI_Name type);

    void createFileLocation();

    char* logger_fl;
    char* camera_fl;
};



#endif
