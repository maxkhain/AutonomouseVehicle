#include "AutonomousEnvironment.h"
//#include "Location.h"
//init

bool AutonomousEnvironment::isRunning=true; 
bool AutonomousEnvironment::isStart=true; 
bool AutonomousEnvironment::isLogging=false; 
Status AutonomousEnvironment::currentStatus=Status(0,0);
Location AutonomousEnvironment::destLocation = Location(0,0);
Location AutonomousEnvironment::currentLocation= Location(0,0);


void AutonomousEnvironment::Initialize()
    {
            //Global veriables
        currentLocation= Location(0,0);
        destLocation = Location(0,0);
        currentStatus=Status(0,0);
        isRunning=true; 
        isStart=false;
        isLogging=true;
    }