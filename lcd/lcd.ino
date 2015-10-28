// SparkFun Serial LCD example 1
// Clear the display and say "Hello World!"

// This sketch is for Arduino versions 1.0 and later
// If you're using an Arduino version older than 1.0, use
// the other example code available on the tutorial page.

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
//#include <SoftwareSerial.h>
//#include "application.h"
//#include "Serial2/Serial2.h"

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

void setup() {
    Serial.begin(9600);
    Serial.println(" Serial Port is working!");

    Serial1.begin(9600);
    delay(500);
    clear();

    pinMode(A7, INPUT);

    unsigned long us = micros();  //check micros() function
    Serial1.print(us,HEX);
    delay(100);
    us = micros();
    Serial1.print(us,HEX);
    delay(5000);

}


void loop() {
    clear();

    Serial.write("Test");
    for (int i = 0; i < 2; i++) {
      Serial1.write("Felix sucks he is very mean!!!!!!!!!!!!!!!!!!!!!!!!!");
      delay(5000);
      clear();

      Serial1.write("nico is awesome he is complete control over felix!!!");
      delay(5000);
      clear();
    }
//    Serial1.write("b!");
    delay(3000);
}
