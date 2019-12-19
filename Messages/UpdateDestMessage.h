#pragma once
#ifndef _UPDATEDESTMESSAGE_H    /* Guard against multiple inclusion */
#define _UPDATEDESTMESSAGE_H
#include "Message.h"
#include "Logger.h"

static int update_message_count=0;
class UpdateDestMessage : public Message
{
private:
    
    int current_message_count;

public:
    UpdateDestMessage();
    virtual bool Process();
    virtual ~UpdateDestMessage() {};
};


#endif
