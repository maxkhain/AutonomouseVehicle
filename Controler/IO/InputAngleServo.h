#pragma once
#ifndef _INPUTANGLESERVO_H    /* Guard against multiple inclusion */
#define _INPUTANGLESERVO_H  

#include "Servo.h"
#include "AutonomousEnvironment.h"


/**InputAngleServo

@note This module is responsible for the calculation of the angle requered and the input to the servo

@params


*/
static Servo myservoAngle(SERVO_ANGLE);


void DiffranceInAngleToPWM(double diff_angle);


#endif 