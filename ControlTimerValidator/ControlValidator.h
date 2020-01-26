#pragma once
#ifndef _CONTROLVALIDATOR_H    /* Guard against multiple inclusion */
#define _CONTROLVALIDATOR_H  

#include "mbed.h"
#include "Logger.h"
#include "AutonomousEnvironment.h"

#include <iostream>
#include <string>
#include <sstream>


class ControlValidator
{

private:

    static const int max_time=(int)((double)(((TIME_CREATE_CONTROL_MESSAGE*1000*1000))*(double)(100+ERROR_IN_PERCENT)/100));
    static const int min_time=(int)((double)(((TIME_CREATE_CONTROL_MESSAGE*1000*1000))*(double)(100-ERROR_IN_PERCENT)/100));
    static int current_timer_in_uSec;
    static int prev_timer_in_uSec;
    
public:

    static void Initialize();    

    static bool ResetTimer();


};
#endif 