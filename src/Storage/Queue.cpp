#include "Queue.h"

// Queue

QueueStorage::QueueStorage(int starting) {
    popI = 0;
    addI = 0;
    size = 0;
    length = starting;
    arr = new StorageItem*[length];
}

// Queue::Queue() : 

QueueStorage::~QueueStorage() {}

// THIS IS NOT NULL SAFE, MUST BE DELETED/COMMENTED IN PRODUCTIONS
//StorageItem* Queue::getItem(int i) {
//    return arr[i];
//}

void QueueStorage::add(StorageItem* item) {
    arr[addI] = item;

    addI++;
    size++;
    // resizes if it goes out of bound
    // we don't want to resize if there is still some spaces

    // checks if there is some space for the external view of the array and are at
    // external end
    if(addI == length){
        // set it back at the beginning
        addI = 0;
        // if theres no space at the beginning, then resize
        if(&arr[addI] != nullptr) {
            addI = length;
            resize();
        }
    };
}

//int Queue::actualLength() {
//    return length;
//}

int QueueStorage::len() {
    return size;
}

void QueueStorage::pop() {
    StorageItem* item = arr[popI];
    if(item != nullptr){
        arr[popI] = nullptr;
        popI++;
        size--;
        if(popI == length){
            popI = 0;
        }
    }
}

// ARRAY MUST BE FULL
void QueueStorage::resize() {

    int oldLength = length;

    length = length * 2;

    StorageItem** temp = new StorageItem*[length];

    // NEED TO BE POPPED ELEMENTS MUST GO FIRST IN ARR
    int shift = popI;
    int i = 0;
    for (; i<(oldLength - popI); i++) {
        temp[i] = arr[shift];
        shift++;
    }

    // ADD THE REMAINING
    for (int j=0; j<popI; j++) {
        temp[i] = arr[j];
        i++;
    }

    popI = 0;
    addI = oldLength;

    delete[] arr;
    arr = temp;

}

