#include "StopMessage.h"
#include "AutonomousEnvironment.h"

StopMessage::StopMessage()
{
    m_messageType = MESSAGESTOP;
    stop_message_count++;
    StopMessage::current_message_count=stop_message_count;
};

bool StopMessage::Process()
{
    Logger::Log("Stop message process number: ",StopMessage::current_message_count);
    //PWM_to_speed_servo = SpeedToPWM(0);  //Update PWM outpute to 0
    AutonomousEnvironment::isRunning = false;
    return true;
}

