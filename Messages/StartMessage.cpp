#include "StartMessage.h"
#include "AutonomousEnvironment.h"

StartMessage::StartMessage()
{
    m_messageType = MESSAGESTART;
    start_message_count++;
    StartMessage::current_message_count=start_message_count;
};

bool StartMessage::Process()
{
    Logger::Log("Start message process number: ",StartMessage::current_message_count);
    AutonomousEnvironment::isStart = true;
    return true;
}

