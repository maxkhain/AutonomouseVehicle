#pragma once
#ifndef _INPUTSPEEDSERVO_H    /* Guard against multiple inclusion */
#define _INPUTSPEEDSERVO_H  

#include "Servo.h"
#include "AutonomousEnvironment.h"



static Servo myservoSpeed(SERVO_SPEED);


void SpeedToPWM(double requested_speed);


#endif 