#include "StorageController.h"

StorageController::StorageController(){
    items = QueueStorage(30);
    SD.begin();
}

bool StorageController::push(StorageItem* item) {
    
    items.add(item);
    
    return true;
};

bool StorageController::pop() {
    
    items.pop();

    return true;
}


bool StorageController::save(StorageItem* item) {
    return true;
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