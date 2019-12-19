#pragma once
#ifndef _CALCULATIONS_H    /* Guard against multiple inclusion */
#define _CALCULATIONS_H  

#include "AutonomousEnvironment.h"
#include "Logger.h"
class Calculations{
    
private: 
//definitions
    static const double  max_speed=MAX_SPEED;
    static const int  accelarate_time=ACCELERATE_TIME;
    static const int  deaccelarate_time=DEACCELERATE_TIME;
    static const double  vehicle_length=VEHICLE_LENGTH; 
    static const int  fps=FPS;
    
public:   
    static double CalculateAngleToDestination();
    static double CalculateDistance();
    static double CalculateSpeed(double distance);
    static void CalculateNewLocation();

};
#endif 
