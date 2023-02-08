#ifndef _QUEUE_
#define _QUEUE_

#include "StorageItem.h"

class ArrayList {

    public:
        ArrayList();
        ~ArrayList();
        
        void resize();
    private:
        int size;
        StorageItem items[100];

};


class Queue {
    public:
        Queue();
        ~Queue();

        void add(StorageItem item);

        void pop();
    private:
        ArrayList arr;
        
};


#endif