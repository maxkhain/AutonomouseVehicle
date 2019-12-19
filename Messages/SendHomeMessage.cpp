#include "SendHomeMessage.h"


SendHomeMessage::SendHomeMessage()
{
    m_messageType = MESSAGESENDHOME;
    send_message_count++;
    SendHomeMessage::current_message_count=send_message_count;
};

bool SendHomeMessage::Process()
{
    Logger::Log("Send home message process number: ", SendHomeMessage::current_message_count);
    return true;
}

