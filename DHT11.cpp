#include "C:\Users\karsh\MATLAB\Projects\Smart Farming with IoT Sensors\DHT11.h"
#include "ardino.h"
#include "DHT.h"
#include "DHT_U.h"

#define DHTPIN 4 
#define DHTTYPE   DHT11
DHT_unified_dht (DHTPIN, DHTTYPE);
uint32_t delaysMS;


// dataDelay uint32 [1,1] Tunable

void setupFunctionDHT11(uint32_T * dataDelay,int size_vector__1){
    Serial.begin(9600);
    dht.begin();
    delaysMS= dataDelay;
}

// Temperature single [1,1]
// Humidity single [1,1]


void stepFunctionDHT11(float * Temperature,int size_vector_1,float * Humidity,int size_vector_2, uint32_T * dataDelay,int size_vector__1){
    delay(delayMS);
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.relative_humidity)){
    }
    else {
        "Humidity=event.relative_humidity;
    }
}