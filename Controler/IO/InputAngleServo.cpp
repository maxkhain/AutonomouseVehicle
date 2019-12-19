#include "InputAngleServo.h"

/*
The InputServo module

	
	

*/
	

void DiffranceInAngleToPWM(double diff_angle)
{
	myservoAngle=diff_angle/MAX_ANGLE;
}
