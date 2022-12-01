#define topIRpin A3
#define IRcount 7
#define topIRthres 30

void setup() {
  Serial.begin(9600);                             
}

int topIRBlocked() {
	float volts = analogRead(topIRpin) * 0.0048828125;
	float sum_distance = 0;
	for (int i = 0; i < IRcount; i++) {
		sum_distance += 65 * pow(volts, -1.10);
	}
	int x = (sum_distance < topIRthres*IRcount) ? 1 : 0;
	if (x == 1) {
		Serial.println("IR SENSOR BLOCKED");
	}
	return x;
}

void loop() {
  Serial.println(topIRBlocked());                                    
}