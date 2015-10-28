////////////////////////////////////////////////////////////////////////////
// From the grove starter kit examples
////////////////////////////////////////////////////////////////////////////

#include "application.h"

#define BUTTONPIN D2
#define BUZZERPIN D4

int melody[] = {1908, 2551, 2551, 2273, 2551, 0, 2024, 1908};
int noteDurations[] = {4,8,8,4,4,4,4,4};

void setup() {
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTONPIN) == 1) {
    for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
      int duration = 1000/noteDurations[thisNote];
      tone(BUZZERPIN, melody[thisNote], duration);
      int pauseBetweenNotes = duration * 1.3;
      delay(pauseBetweenNotes);
      noTone(BUZZERPIN);
    }
  }
}
