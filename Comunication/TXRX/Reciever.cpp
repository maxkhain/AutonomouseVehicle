#include "Reciever.h"

Message* Reciever::RecieveMessageTriggered()
{
    Message* current_message;
    //read buffer from Xbee and create a Message
    //type = the message type as we recieved from the Xbee(0-upgDest,1 Stop)
    Message::MessageType type = Message::MESSAGEUPDATEDEST;

    switch(type) {
        case Message::MESSAGESTOP:
            //pc.printf("<<<Creating stop message>>>");
            current_message=new StopMessage();//Recieved stop
            break;
        case Message::MESSAGEUPDATEDEST:
            //pc.printf("<<<Creating update destination message>>>");
            //new_destination_fromXbee=;
            current_message=new UpdateDestMessage(); //Reciever new location
            break;
        case Message::MESSAGESTART:
            //pc.printf("<<<Creating start message>>>");
            //new_destination_fromXbee=;
            current_message=new StartMessage(); 
            current_message->Process();
            return NULL;
            break;
    }
    return current_message;

}