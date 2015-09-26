//Using a bean to send serial command via Bluetooth and click slides!
//Written by: kennethlimcp in Sept 2015

#define but_left 5
#define but_right 0

unsigned long old_time = millis();

void setup() {
  // Turn off the LED
  Bean.setLed(0, 0, 0);
  pinMode(but_left,INPUT_PULLUP);
  pinMode(but_right,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
//  connected = Bean.getConnectionState();
//  if(connected){
    // Turn the LED green
		if(millis() - old_time > 3000){
			Bean.setLed(20, 0, 0);
			delay(50);
			Bean.setLed(0, 0, 0);
			old_time = millis();
		}

     if(digitalRead(but_left) == LOW){
      Serial.print("l");

      for(int i=0; i<10;i++){
        delay(100);
        if(!Serial.available()){
          Serial.print("l");
        }
        else{
          Serial.read();
          break;
        }
     }
    while(digitalRead(but_left) == LOW);
   }
   else if(digitalRead(but_right) == LOW){
      Serial.print("r");

      for(int i=0; i<10;i++){
        delay(100);
        if(!Serial.available()){
          Serial.print("r");
      }
      else{
        Serial.read();
        break;
      }
      while(digitalRead(but_right) == LOW);

    }
	}
}
