#include "UpdateDestMessage.h"

UpdateDestMessage::UpdateDestMessage()
{
    m_messageType = MESSAGEUPDATEDEST;
    update_message_count++;
    UpdateDestMessage::current_message_count=update_message_count;
};

bool UpdateDestMessage::Process()
{
    Logger::Log("Update message process number: ",UpdateDestMessage::current_message_count );
    //destLocation = GetXbeeDest();//after parsing the recieved information from the xbee
    return true;
}

