#pragma once
#ifndef _STARTMESSAGE_H    /* Guard against multiple inclusion */
#define _STARTMESSAGE_H
#include "Message.h"
#include "Logger.h"

static int start_message_count=0;

class StartMessage : public Message
{
private:
    
    int current_message_count;

public:
    StartMessage();
    virtual bool Process();
    virtual ~StartMessage() {};
};


#endif
