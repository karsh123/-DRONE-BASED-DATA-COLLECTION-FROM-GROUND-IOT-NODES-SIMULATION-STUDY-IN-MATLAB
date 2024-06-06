#include "C:\Users\karsh\MATLAB\Projects\Smart Farming with IoT Sensors\FC28.h"
#include "arduino.h"

#define FC28_PIN A0

// Calibration constants for converting sensor readings to soil moisture percentage
const float VOLTAGE_MIN = 0.0; // Minimum voltage output from the sensor (dry soil)
const float VOLTAGE_MAX = 5.0; // Maximum voltage output from the sensor (wet soil)
const float MOISTURE_MIN = 0;  // Corresponding minimum soil moisture percentage
const float MOISTURE_MAX = 100;// Corresponding maximum soil moisture percentage

// dataDelay uint32 [1,1] Tunable

void setupFunctionFC28(uint32_T * dataDelay,int size_vector__1){
    pinMode(FC28_PIN, INPUT);
}

// Voltage double [1,1]


void stepFunctionFC28(double * Voltage,int size_vector_1, uint32_T * dataDelay,int size_vector__1){
    / Read the analog voltage from the FC-28 sensor
    int sensorValue = analogRead(FC28_PIN);
    
    // Convert the sensor reading to a voltage value (0-5V)
    float voltage = sensorValue * (VOLTAGE_MAX / 1023.0);
    
    // Convert voltage to soil moisture percentage using linear interpolation
    float moisturePercentage = mapFloat(voltage, VOLTAGE_MIN, VOLTAGE_MAX, MOISTURE_MIN, MOISTURE_MAX);
    
    // Set the output voltage value
    *Voltage = moisturePercentage;
  
}

// Function to perform linear interpolation
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}