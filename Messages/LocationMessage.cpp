#include "LocationMessage.h"


LocationMessage::LocationMessage()
{
    m_messageType = MESSAGELOCATION;
    location_message_count++;
    LocationMessage::current_message_count=location_message_count;
};

bool LocationMessage::Process()
{
    Logger::Log("Location message process number: ", LocationMessage::current_message_count);

    //this is only for version without GPS
    Calculations::CalculateNewLocation();

    AutonomousEnvironment::currentLocation= GPSApi::GetGPSLocation();
    Logger::Log("Current location", AutonomousEnvironment::currentLocation);
    SendHomeMessage* new_message = new SendHomeMessage();
    MessageQueue::EnQueue(new_message);

    return true;
}
