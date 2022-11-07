void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
}

void line_sensor_reading() {
	// module to read from a line sensor
}

void serial_communication(){
	// module to check communication across serial link
	Serial.println("Hello World");
}

void LED_test(){
	digitalWrite(13, HIGH);       // sets the digital pin 13 on
  delay(1000);                  // waits for a second
  digitalWrite(13, LOW);        // sets the digital pin 13 off
  delay(1000);                  // waits for a second
}

void loop() {
	// put your main code here, to run repeatedly:
	serial_communication();
  LED_test();

}
