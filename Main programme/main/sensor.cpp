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