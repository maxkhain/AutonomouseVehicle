#pragma once
#ifndef _INPUTANGLESERVO_H    /* Guard against multiple inclusion */
#define _INPUTANGLESERVO_H  

#include "Servo.h"
#include "AutonomousEnvironment.h"


static Servo myservoAngle(SERVO_ANGLE);


void DiffranceInAngleToPWM(double diff_angle);


#endif 