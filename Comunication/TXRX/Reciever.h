#pragma once
#ifndef _RECIEVER_H    /* Guard against multiple inclusion */
#define _RECIEVER_H  

#include "Location.h"
#include "Message.h"

#include "UpdateDestMessage.h"
#include "StopMessage.h"
#include "StartMessage.h"

class Reciever{
    
private: 
    static Location new_destination_fromXbee;
    
    
public:   
    static Message* RecieveMessageTriggered();
    
    

};


#endif



