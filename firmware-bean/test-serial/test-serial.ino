void setup() {
  // put your setup code here, to run once:
 Serial.begin(57600);
 Bean.setLed(255,255,255);
}

void loop() {
  Bean.setLed(255,255,255);
  Serial.println("me");
	Bean.sleep(1000);
	Bean.setLed(0,0,0);
	Bean.sleep(1000);
}
