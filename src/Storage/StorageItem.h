#ifndef STORAGEITEM
#define STORAGEITEM

enum SI_Name {Logger, Camera};

struct StorageItem {
    char data[80];
    SI_Name type;
};


#endif