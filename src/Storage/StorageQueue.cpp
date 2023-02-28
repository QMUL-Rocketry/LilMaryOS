#include "StorageQueue.h"

// Queue

QueueStorage::QueueStorage(int starting) {
    popI = 0;
    addI = 0;
    size = 0;
    length = starting;
    arr = new StorageItem*[length];
}

// find out how to delete arr dynamic arr - it looks fine
QueueStorage::~QueueStorage() {
    delete[] arr;
}

// CHECK CODE
// 52, 56 --> POINTING TO STORAGE ADDRESS. REMOVE &. PROBABLY WOULD WORK.
void QueueStorage::add(StorageItem *item) {
    // checks if there is some space for the internal view of the array and are at
    // at internal end
    if(addI == length){
        // set it back at the beginning
        addI = 0;
        // if theres no space at the beginning, then resize
        if(&arr[addI] != nullptr) {
            addI = length;
            resize();
        }
    } else if(&arr[addI] != nullptr) {
        resize();
    }

    // idek why i have a size var
    arr[addI] = item;
    addI++;
    size++;

}

//int Queue::actualLength() {
//    return length;
//}

int QueueStorage::len() {
    return size;
}

StorageItem *QueueStorage::pop() {
    StorageItem *item = arr[popI];
    if(item != nullptr){
        arr[popI] = nullptr;
        popI++;
        size--;
        if(popI == length){
            popI = 0;
        }
        return item;
    }
    return nullptr;
}

// ARRAY MUST BE FULL
void QueueStorage::resize() {

    int oldLength = length;
    length = length * 2;

    StorageItem **temp = new StorageItem*[length];

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

    // find out how to delete arr dynamic arr - it looks fine
    delete[] arr;
    arr = temp;

}