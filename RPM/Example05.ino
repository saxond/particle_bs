
#include "HttpClient.h"
#include <math.h>
//#include "application.h"

#include "TM1637.h"


void dispNum(unsigned int num);

// name the pins
#define CLK D4
#define DIO D5
TM1637 tm1637(CLK,DIO);

HttpClient http;

http_header_t headers[] = {
    { "X-Api-Key" , ""},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

// This routine runs only once upon reset
void setup()
{
  tm1637.set();                                 // cofig TM1637
  tm1637.init();                                // clear the display
  Serial.begin(9600);                           // init serial port on USB interface
  Serial.print("Setup");
}

// This routine loops forever
void loop()
{
  Serial.print("loop");

  http_request_t request;
  http_response_t response;

  request.hostname = "";
  request.port = 443;
  request.path = "/v2/applications/XXX/metrics/data.json?names[]=OtherTransaction/Custom/com.newrelic.metricindexer.consumer.MetricConsumer&values[]=requests_per_minute&summarize=true";


  // The library also supports sending a body with your request:
  //request.body = "{\"key\":\"value\"}";

  // Get request
  http.get(request, response, headers);
  Serial.print("Application>\tResponse status: ");
  Serial.println(response.status);
  Serial.println(response.body);


  dispNum((unsigned int) 666);  // display devil cock
  delay(200);
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
