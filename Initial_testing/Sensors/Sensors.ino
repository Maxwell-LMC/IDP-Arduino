int lineLpin = 2;
int lineFpin = 3;
int lineRpin = 4;
int lineBpin = 5;

int lineLvalue = 0;
int lineFvalue = 0;
int lineRvalue = 0;
int lineBvalue = 0;

int orientation = 0;


void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
}

void lineSensorsRead(){
	// module to read from line sensors
	lineLvalue = digitalRead(lineLpin);
	lineFvalue = digitalRead(lineFpin);
	lineRvalue = digitalRead(lineRpin);
	lineBvalue = digitalRead(lineBpin);
}

bool onLine(int value){
	// module to say if the sensor is on the line
	if (value == 1){
		return true;
	};
	return false;
}

int relativeToLine(bool onLineL, bool onLineF, bool onLineR, bool onLineB){
	// module to say which way the robot is facing
	if (!onLineL && onLineF && !onLineR && onLineB){
		// the robot is on a straight line returns 0
		return 0;
	} else if (onLineL && onLineF && !onLineR && onLineB){
		// the robot is on a left branch
		return 1;
	} else if (!onLineL && onLineF && onLineR && onLineB) {
		// the robot is on a right branch
		return 2;
	} else if (onLineL && onLineF && onLineR && onLineB) {
		// the robot is on a cross
		return 3;
	} else if (!onLineL && onLineB && onLineR){
		// the robot is facing too far left
		return 4;
	} else if (onLineL && onLineB && !onLineR) {
		// the robot is facing too far right
		return 5;
	}
	Serial.println("unknown orientation");
	return 1000;
}

void responseToOrientation(int o){
	// carries out the response to the orientation
	switch (o) {
		case 0:
			// if the robot is straight
			Serial.println("Straight");
			break;
		case 1:
			// if the robot is at a left branch
			Serial.println("Left branch");
			break;
		case 2:
			// if the robot is at a right branch
			Serial.println("Right branch");
			break;
		case 3:
			// if the robot is at a cross
			Serial.println("Cross");
			break;
		case 4:
			// if the robot is too far left
			Serial.println("Left");
			break;
		case 5:
			// if the robot is too far right
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
	Serial.print(lineFvalue);
	Serial.print(" ");
	Serial.print(lineRvalue);
	Serial.print(" ");
	Serial.println(lineBvalue);
	delay(300);
	orientation = relativeToLine(onLine(lineLvalue), onLine(lineFvalue), onLine(lineRvalue), onLine(lineBvalue));
	responseToOrientation(orientation);
}
