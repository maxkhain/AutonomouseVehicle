#include "mbed.h"

#include "Reciever.h"
#include "Sender.h"

#include "MessageQueue.h"

#include "Location.h"
#include "CurrentStatus.h"

#include "Message.h"
#include "ControlMessage.h"
#include "LocationMessage.h"
#include "UpdateDestMessage.h"
#include "StopMessage.h"
#include "SendHomeMessage.h"

//#include "Serial_Packet.h"

#include "AutonomousEnvironment.h"

#include "Logger.h"
#include "WDG.h"


//User button
InterruptIn  LogButton(USER_BUTTON);

//Interrupt flags
Ticker message_location_timer_interrupt;//time interrupt
Ticker message_control_timer_interrupt;//time interrupt
Ticker WDG_timer_interrupt;//time interrupt


//XBEE interrupt, recieved new message

void CreateLocationMessage()
{
    //Logger::Log("<<<Creating location message>>>");
    LocationMessage* new_message = new LocationMessage();
    MessageQueue::EnQueue(new_message);
}

void CreateControlMessage()
{

    ControlMessage* new_message = new ControlMessage();
    MessageQueue::EnQueue(new_message);
    //Logger::Log("<<<Creating Control message>>>");
}

void CreateRecievedMessage()
{
    Message* current_message;
    current_message = Reciever::RecieveMessageTriggered();
    MessageQueue::EnQueue(current_message);
}
void ToggleLogger()
{
    AutonomousEnvironment::isLogging=!AutonomousEnvironment::isLogging;
}

int main()
{
    Logger::Log("--- Starting main ---");
    AutonomousEnvironment::Initialize();
    Logger::Initialize();
    Watchdog::Initialize();
    LogButton.fall(&ToggleLogger);
    bool is_first_control_message=true;
    //Test for dest
    AutonomousEnvironment::destLocation=Location(15,15);//test destination

    message_location_timer_interrupt.attach(&CreateLocationMessage, TIME_CREATE_LOCATION_MESSAGE);   //every TimeCreateLocationMessage in sec
    message_control_timer_interrupt.attach(&CreateControlMessage, TIME_CREATE_CONTROL_MESSAGE);      //every TimeCreateControlMessage in sec
    WDG_timer_interrupt.attach(&Watchdog::Count,WDG_TIMER );                                         //every WDG_TIMER in sec


    //  set WDG count to 0
    Watchdog::kick();

    //Test need to recieve start message
    AutonomousEnvironment::isStart = true;



    while(AutonomousEnvironment::isRunning) {
        //Logger::Log("Destination is ",AutonomousEnvironment::destLocation);
        if(AutonomousEnvironment::isStart) {
            Logger::Log("Poping message from queue");
            Message* current_message = MessageQueue::DeQueue();
            if(current_message->m_messageType==Message::MESSAGECONTROL) {                            //check if control message for WDG
                if(is_first_control_message) {
                    is_first_control_message=false;
                    Watchdog::kick();
                } else
                    AutonomousEnvironment::isRunning=Watchdog::kick();                                //if kick returns false stop the car
            }
            if(current_message!=NULL) {                                                               //check if queue was empty
                //Logger::Log("currently preccessing message type ",current_message.m_messageType);
                current_message->Process();
                delete current_message;
            }

            else
                Logger::Log("NULL MESSAGE");



        }
        //wait_ms(TIME_PER_CYCLE);//timeout for the main loop in mili sec
    }
    //Stopping the car and freeing all the alocated objects
    Message* current_message= new StopMessage();
    current_message->Process();
    return 0;
}







