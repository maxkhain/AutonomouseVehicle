#pragma once
#ifndef _MESSAGEQUEUE_H    /* Guard against multiple inclusion */
#define _MESSAGEQUEUE_H  

#include "Message.h"
#include "Logger.h"
#include "rtos.h"

class MessageQueue {
private:
    
    static Queue<Message, 16> message_queue;
    
public:
    static int queue_counter;
    static void EnQueue(Message* new_message);
    static Message* DeQueue();    
};


#endif 
