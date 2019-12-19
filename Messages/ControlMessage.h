#pragma once
#ifndef _CONTROLMESSAGE_H    /* Guard against multiple inclusion */
#define _CONTROLMESSAGE_H  

#include "Message.h"
#include "Location.h"
#include "Calculations.h"
#include "Logger.h"
#include "AutonomousEnvironment.h"

static int control_message_count=0;

class ControlMessage: public Message {
private:
    
    int current_message_count;

public:
    ControlMessage();
    virtual bool Process();  
    virtual ~ControlMessage(){};
};


#endif 
