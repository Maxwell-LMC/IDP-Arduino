int lineLpin = 2;
int lineFpin = 3;
int lineRpin = 4;
int lineBpin = 5;

int lineLvalue = 0;
int lineFvalue = 0;
int lineRvalue = 0;
int lineBvalue = 0;

int orientation = 0;

void lineSensorsRead() {
	// module to read from line sensors
	lineLvalue = digitalRead(lineLpin);
	lineFvalue = digitalRead(lineFpin);
	lineRvalue = digitalRead(lineRpin);
	lineBvalue = digitalRead(lineBpin);
}

bool onLine(int value) {
	// module to say if the sensor is on the line
	if (value == 1) {
		return true;
	};
	return false;
}

int lineInformation(bool onLineL, bool onLineF, bool onLineR, bool onLineB)