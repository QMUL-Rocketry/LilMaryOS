#include "StorageController.h"
#include "time.h"

StorageController::StorageController(){
    items = QueueStorage(30);
    SD.begin();
    createFileLocation();
}

StorageController::~StorageController(){
    delete logger_fl;
    delete camera_fl;
}

void StorageController::run() {
    save();
};

static char* generateTimeStamp()
{
    time_t timer;
    char* buffer = new char[50];
    struct tm* tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 50, "%Y-%m-%d-%H:%M:%S", tm_info);
    return buffer;
}

void StorageController::createFileLocation() {
    char* ts = generateTimeStamp();
    // logger file name
    logger_fl = new char[sizeof(LOG_FILE)+sizeof(ts)];
    // strcat(logger_fl, LOG_LOC); // NEED TO ADD LOG LOCATION AND IMPLEMENT THE FOLDER CHECK
    strcat(logger_fl, ts);
    strcat(logger_fl, LOG_FILE);
    // video file - NOTE WRONG CODE - MUST CHANGE
    // camera_fl = new char[sizeof(VIDEO_FILE)+sizeof(ts)];
    // strcat(camera_fl, ts);
    // strcat(camera_fl, VIDEO_FILE);
};

void StorageController::add(StorageItem* item) { items.add(item); };

bool StorageController::save() { return forceSave(items.pop()); }

bool StorageController::forceSave(StorageItem* item) {
    if (item == nullptr) {
        return write(getType(item->type), item->data);
    }
    return false;
}

void StorageController::flush(){
    for(int i = 0; i<items.len(); i++){
        save();
    }
};

char* StorageController::getType(SI_Name type) {
    switch (type)
    {
    case SI_Name::Logger:
        return logger_fl;
    case SI_Name::Camera:
        return camera_fl;
    default:
        break;
    }
     
    return "def.txt";
    // return DEF_FILE;
}

// maybe we want to keep opening this file
// until a new type/different one comes along
bool StorageController::write(char loc[], char data[]) {
    File f = SD.open(loc, FILE_WRITE);
    if (f) {
        f.println(data);
        f.close();
        return true;
    }
    return false;
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