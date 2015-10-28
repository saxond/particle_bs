#include "application.h"

#define BUTTONPIN D2
#define BUZZERPIN D1
#define ROTORPIN A0


void setup() {
  Serial.begin(9600);
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
//  Serial.println("Test");
  if (digitalRead(BUTTONPIN) == 1) {
      int freq = analogRead(ROTORPIN);
      Serial.println(freq);

      tone(BUZZERPIN, freq, 1000/4);
      delay(4);
      noTone(BUZZERPIN);
  }
}
