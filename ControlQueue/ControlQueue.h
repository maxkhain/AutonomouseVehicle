#pragma once
#ifndef _CONTROLQUEUE_H    /* Guard against multiple inclusion */
#define _CONTROLQUEUE_H  

#include "Message.h"
#include "Logger.h"
#include "rtos.h"

/**ControlQueue

@note this is a static queue for the ControlQueue that we are using in the main


*/

class ControlQueue {
private:
    
    static Queue<Message, 16> control_queue;
    
public:
    static int queue_counter;
    static bool flag_is_empty;
    static void EnQueue(Message* new_message);
    static Message* DeQueue();    
};


#endif 
