
#include "WDG.h"

int Watchdog::count;




void Watchdog::Initialize(){
    Watchdog::count =0;    
    Logger::Log("Wdg max count is: ",max_count);
    Logger::Log("Wdg min count is: ",min_count);
}

void Watchdog::Count()
{
    count ++;
}

bool Watchdog::kick()
{
    bool check=true;
    if(count>=max_count) { //check if too slow
        Logger::Log("Loop too slow");
        check = false;
    } else if(count<=min_count) { //check if too fast
        Logger::Log("Loop too fast");
        check = false;
    }
    Logger::Log("Wdg count is: ",count);
    count=0;
    return check;
}
