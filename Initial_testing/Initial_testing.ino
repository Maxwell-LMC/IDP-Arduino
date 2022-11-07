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
	// module to test turning LEDs on and off

}

void loop() {
	// put your main code here, to run repeatedly:
	serial_communication();
}
