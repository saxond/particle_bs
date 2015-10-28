
void setup() {
  Serial.begin(9600); // start Core with Serial terminal Closed, then open serial terminal

  while(!Serial.available()) SPARK_WLAN_Loop();

  Serial.print("TEST");
}

void loop() {
  Serial.print("SHIT");
}
