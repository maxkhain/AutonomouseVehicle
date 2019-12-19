#include "InputSpeedServo.h"


/*
The InputEngine module

	
	

*/

void SpeedToPWM(double requested_speed)
{
	myservoSpeed=requested_speed/MAX_SPEED;
}
