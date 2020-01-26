#pragma once
#ifndef _CALCULATIONS_H    /* Guard against multiple inclusion */
#define _CALCULATIONS_H  


/**Calculations 

@note this calss has all the control calculation called from ControlMessage

@params


*/


#include "AutonomousEnvironment.h"
#include "Logger.h"
class Calculations{
    
private: 
//definitions
    static const double  max_speed=MAX_SPEED;
    static const int  accelarate_time=ACCELERATE_TIME;
    static const int  deaccelarate_time=DEACCELERATE_TIME;
    static const double  vehicle_length=VEHICLE_LENGTH; 
    
    
public:   
    //Control calculation for angle
    //retrun double angle in radian
    static double CalculateAngleToDestination();
    
    //Calculating distance to destination point
    //return double distance from destination
    static double CalculateDistance();
    
    //Calculating the needed speed according to the distance left to the destination
    //input double the distance to destination point
    //return double speed
    static double CalculateSpeed(double distance);
    
    //For testing only, should be changed to GPS later
    //Updating current location global param to the calculated location according to current speed and time passed
    static void CalculateNewLocation();

};
#endif 
