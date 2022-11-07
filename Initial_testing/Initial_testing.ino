line1pin = A0;
int line1Value = 0;


void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);


}

void line_sensor_reading() {
	// module to read from a line sensor
	line1Value = analogRead(line1pin);
	Serial.printLn(line1Value);
}

void serial_communication(){
	// module to check communication across serial link
	Serial.println("Hello World");
}

void LED_test(){
	// module to test LEDs
	digitalWrite(13, HIGH);       // sets the digital pin 13 on
	delay(1000);                  // waits for a second
	digitalWrite(13, LOW);        // sets the digital pin 13 off
	delay(1000);                  // waits for a second
}

void loop() {
	// put your main code here, to run repeatedly:
	serial_communication();
	LED_test();
	line_sensor_reading();
}
