#pragma once
#ifndef _WDG_H    /* Guard against multiple inclusion */
#define _WDG_H  


#include "mbed.h"
#include "Logger.h"
#include "AutonomousEnvironment.h"



class Watchdog
{

private:

    static const int max_count=(int)((double)(((TIME_CREATE_CONTROL_MESSAGE/WDG_TIMER))*(double)(100+ERROR_IN_PERCENT)/100));
    static const int min_count=(int)((double)(((TIME_CREATE_CONTROL_MESSAGE/WDG_TIMER))*(double)(100-ERROR_IN_PERCENT)/100));
    static int count;
public:

    static void Initialize();
    static void Count();

    // "kick" or "feed" the dog - reset the watchdog timer
    // by writing this required bit pattern
    static bool kick();


};
#endif 