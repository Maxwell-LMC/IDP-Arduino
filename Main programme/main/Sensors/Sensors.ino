int lineLpin = 2;
int lineMpin = 3;
int lineRpin = 4;

int lineLvalue = 0;
int lineMvalue = 0;
int lineRvalue = 0;

int orientation = 0;


void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
}

void lineSensorsRead(){
	// module to read from line sensors
	lineLvalue = digitalRead(lineLpin);
	lineMvalue = digitalRead(lineMpin);
	lineRvalue = digitalRead(lineRpin);
}

bool onLine(int value){
	// module to say if the sensor is on the line
	if (value == 1){
		return true;
	};
	return false;
}

int relativeToLine(bool onLineL, bool onLineM, bool onLineR){
	// module to say which way the robot is facing
	// returns 0 for straight, 1 for left and 2 for right
	if (!onLineL && onLineM && !onLineR){
		return 0;
	} else if (onLineL && onLineM && !onLineR){
		return 2;
	} else if (!onLineL && onLineM && onLineR){
		return 1;
	}
	Serial.println("unknown orientation");
	return 3;
}

void responseToOrientation(int o){
	// carries out the response to the orientation
	switch (o) {
		case 0:
			// if the robot is straight
			Serial.println("Straight");
			break;
		case 1:
			// if the robot is left
			Serial.println("Left");
			break;
		case 2:
			// if the robot is right
			Serial.println("Right");
			break;
		default:
			// unkown orientation
			Serial.println("Unknown");
			break;
	};
}


void loop() {
	// put your main code here, to run repeatedly:
	lineSensorsRead();
	Serial.print(lineLvalue);
	Serial.print(" ");
	Serial.print(lineMvalue);
	Serial.print(" ");
	Serial.println(lineRvalue);
	delay(100);
	orientation = relativeToLine(onLine(lineLvalue), onLine(lineMvalue), onLine(lineRvalue));
	responseToOrientation(orientation);
}
