#include "ControlValidator.h"

int ControlValidator::current_timer_in_uSec;
int ControlValidator::prev_timer_in_uSec;



void ControlValidator::Initialize()
{
    ControlValidator::prev_timer_in_uSec =Logger::timer.read_us();
    Logger::Log("ControlValidator max count is: ",max_time);
    Logger::Log("ControlValidator min count is: ",min_time);
}



bool ControlValidator::ResetTimer()
{
    bool check=true;
    current_timer_in_uSec = Logger::timer.read_us();
    if(current_timer_in_uSec-prev_timer_in_uSec>=max_time) { //check if too slow
        Logger::Log("Loop too slow");
        check = false;
    } else if(current_timer_in_uSec-prev_timer_in_uSec<=min_time) { //check if too fast
        Logger::Log("Loop too fast");
        check = false;
    }
    Logger::Log("ControlValidator time diffrance is: ",current_timer_in_uSec-prev_timer_in_uSec);
    prev_timer_in_uSec=current_timer_in_uSec;
    
    return check;
}
