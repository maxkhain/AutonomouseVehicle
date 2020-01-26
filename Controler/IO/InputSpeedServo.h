#pragma once
#ifndef _INPUTSPEEDSERVO_H    /* Guard against multiple inclusion */
#define _INPUTSPEEDSERVO_H  

#include "Servo.h"
#include "AutonomousEnvironment.h"

/**InputSpeedServo

@note This module is responsible for the calculation of the speed requered and the input to the servo

@params


*/

static Servo myservoSpeed(SERVO_SPEED);


void SpeedToPWM(double requested_speed);


#endif 