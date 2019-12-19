#pragma once
#ifndef _LOCATIONMESSAGE_H    /* Guard against multiple inclusion */
#define _LOCATIONMESSAGE_H

#include "Message.h"
#include "GPSApi.h"
#include "SendHomeMessage.h"
#include "AutonomousEnvironment.h"
#include "MessageQueue.h"
#include "Logger.h"
#include "Calculations.h"

static int location_message_count=0;

class LocationMessage : public Message
{
private:
    
    int current_message_count;

public:
    LocationMessage();
    virtual bool Process();
    virtual ~LocationMessage() {};
};


#endif
