
#include <math.h>
#include "application.h"

#include "TM1637.h"


void dispNum(unsigned int num);

// name the pins
#define CLK D4
#define DIO D5
TM1637 tm1637(CLK,DIO);

int displayNum(String num) {
  Serial.print(num);
  char* buf = new char[num.length() + 1];
  num.toCharArray(buf, num.length() + 1);
  dispNum(atoi(buf));
  return 0;
}

// This routine runs only once upon reset
void setup()
{
  tm1637.set();                                 // cofig TM1637
  tm1637.init();                                // clear the display
  Serial.begin(9600);                           // init serial port on USB interface
  Serial.print("Setup");

  dispNum(666);
  Particle.function("display", displayNum);
}

// This routine loops forever
void loop()
{
  //Serial.print("loop");

/*
  dispNum((unsigned int) 666);  // display devil cock
  delay(200);

  dispNum((unsigned int) 555);  // display devil cock
  delay(200);
  */
}

// display a integer value less then 10000
void dispNum(unsigned int num)
{
  int8_t TimeDisp[] = {0x01,0x02,0x03,0x04};    // limit the maximum number

  if(num > 9999) num = 9999;
  TimeDisp[0] = num / 1000;
  TimeDisp[1] = num % 1000 / 100;
  TimeDisp[2] = num % 100 / 10;
  TimeDisp[3] = num % 10;
  tm1637.display(TimeDisp);
}
