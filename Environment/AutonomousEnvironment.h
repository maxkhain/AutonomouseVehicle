#pragma once
#ifndef _AUTONOMOUSENVIRONMENT_H    /* Guard against multiple inclusion */
#define _AUTONOMOUSENVIRONMENT_H

#include <queue>
#include "Message.h"
#include "Location.h"
#include "CurrentStatus.h"

//This class is for the global parameters for the autonomous vehicle


#define TIME_CREATE_CONTROL_MESSAGE 0.5  //time wait between cycles in  sec
#define TIME_CREATE_LOCATION_MESSAGE 3   //time wait between cycles in  sec
#define WDG_TIMER 0.0001                 //time wait bfor counter ticks in sec
#define LOG_TIMER 0.3

#define ERROR_IN_PERCENT 5               //error of control message timing in percent

#define MAX_SPEED 2                      // m/s
#define ACCELERATE_TIME 8                //in sec
#define DEACCELERATE_TIME 3              //in sec
#define VEHICLE_LENGTH 0.5               //meters
#define MAX_ANGLE 0.785                  // radian

#define SERVO_ANGLE D11                  //servo for turns define
#define SERVO_SPEED D12                  //Servo for speed control define

class  AutonomousEnvironment
{


public:

    //Global veriables
    static Location currentLocation;
    static Location destLocation;        //location of the destination
    static Status currentStatus;
    static bool isRunning;               //bool if still running, if isRunning = false the car will stop
    static bool isStart;
    static bool isLogging;
    static void Initialize();


};
#endif
