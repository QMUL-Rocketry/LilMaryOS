#include "StorageController.h"

StorageController::StorageController(){
    items = QueueStorage(30);
    SD.begin();
}

StorageController::~StorageController(){}

bool StorageController::push(StorageItem* item) {
    
    items.add(item);
    
    return true;
};

// NULL SAFETY CHECKKKKKKKKKKK
StorageItem* StorageController::pop() {
    return items.pop();
}

// PERFORM NULL SAFETY CHECK
bool StorageController::save(StorageItem* item) {
    if (item == nullptr) {
        return false;
    }
    return true;
}


void StorageController::getType(StorageItem *item) {
    switch (item->type)
    {
    case SI_Name::Logger:
        /* code */
        break;
    case SI_Name::Camera:
        break;
    default:
        break;
    }
}
// #include <SD.h>

// void init(int chipSelect) {

//     while(!SD.begin(chipSelect)){
//         Serial.println("initialization failed. Things to check:");
//         Serial.println("1. is a card inserted?");
//         Serial.println("2. is your wiring correct?");
//         Serial.println("3. did you change the chipSelect pin to match your shield or module?");
//         Serial.println("Note: press reset button on the board and reopen this Serial Monitor after fixing your issue!");
//         delay(1000);
//     }

// }