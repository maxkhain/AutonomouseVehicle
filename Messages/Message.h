#pragma once
#ifndef _MESSAGE_H    /* Guard against multiple inclusion */
#define _MESSAGE_H  




class Message {
public:
typedef enum messageType{
    MESSAGE,
    MESSAGELOCATION,
    MESSAGEUPDATEDEST,
    MESSAGECONTROL,
    MESSAGESTOP,
    MESSAGESTART,
    MESSAGESENDHOME   
    
}MessageType;
    
private:
         
public:

     MessageType m_messageType; 
 
 //    Message(){
 //        m_messageType = MESSAGE;
 //    };
     bool virtual Process() = 0;
     virtual ~Message(){
     };

    
};



#endif 
