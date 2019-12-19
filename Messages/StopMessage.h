#pragma once
#ifndef _STOPMESSAGE_H    /* Guard against multiple inclusion */
#define _STOPMESSAGE_H
#include "Message.h"
#include "Logger.h"

static int stop_message_count=0;

class StopMessage : public Message
{
private:
    
    int current_message_count;

public:
    StopMessage();
    virtual bool Process();
    virtual ~StopMessage() {};
};


#endif
