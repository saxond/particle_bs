// SparkFun Serial LCD example 1
// Clear the display and say "Hello World!"

// This sketch is for Arduino versions 1.0 and later
// If you're using an Arduino version older than 1.0, use
// the other example code available on the tutorial page.

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
//#include <SoftwareSerial.h>
#include "application.h"
#include "Serial2/Serial2.h"

// Attach the serial display's RX line to digital pin 2
//SoftwareSerial mySerial(3,2); // pin 2 = TX, pin 3 = RX (unused)



void lineReturn() {
    Serial1.write(254); // move cursor to beginning of first line
    Serial1.write(128);
}

void clear() {
    lineReturn();
    for (int i = 0; i < 2; i++) {
        Serial1.write("                "); // clear display
    }
}

int sensorValue;
int buzzerPin = D3;
int lightPin = A0;

void setup() {
    Serial1.begin(9600);
    delay(500);
    clear();

    Spark.variable("getLight", &sensorValue, INT);
    pinMode(A7, INPUT);
    pinMode(lightPin, INPUT);
    pinMode(buzzerPin, OUTPUT);  // buzzer pin setup

    unsigned long us = micros();  //check micros() function
    Serial1.print(us,HEX);
    delay(100);
    us = micros();
    Serial1.print(us,HEX);
    delay(5000);

}

void loop() {
    clear();

    sensorValue = analogRead(lightPin);       // read analog input pin 0
    //Serial.println(sensorValue, DEC);  // prints the value read

    digitalWrite(buzzerPin, sensorValue > 400 ? HIGH : LOW);

    Serial1.print(sensorValue, DEC);

//    Serial1.write("b!");
    delay(500);
}
