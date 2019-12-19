#pragma once
#ifndef _SENDHOMEMESSAGE_H    /* Guard against multiple inclusion */
#define _SENDHOMEMESSAGE_H
#include "Message.h"
#include "Logger.h"

static int send_message_count=0;

class SendHomeMessage : public Message
{
private:
    
    int current_message_count;

public:
    SendHomeMessage();
    virtual bool Process();
    virtual ~SendHomeMessage() {};
};


#endif
