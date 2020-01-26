#include "mbed.h"

#include "Reciever.h"
#include "Sender.h"

#include "MessageQueue.h"
#include "ControlQueue.h"

#include "Location.h"
#include "CurrentStatus.h"

#include "Message.h"
#include "ControlMessage.h"
#include "LocationMessage.h"
#include "UpdateDestMessage.h"
#include "StopMessage.h"
#include "SendHomeMessage.h"

#include "AutonomousEnvironment.h"

#include "Logger.h"
#include "WDG.h"
#include "ControlValidator.h"


/*

This code as compiled for NUCLEO-L476RG

All defined params are configured in AutonomousEnvironment.h under Environment
Servo outputs are configured in AutonomousEnvironment.h

communication and GPS are onlt templates and left under TODO

*/

//User button
InterruptIn  LogButton(USER_BUTTON);

//Interrupt flags
Ticker message_location_timer_interrupt;       //time interrupt
Ticker message_control_timer_interrupt;        //time interrupt
Ticker WDG_timer_interrupt;                    //time interrupt
Ticker Log_timer_interrupt;                    //time interrupt


Thread thread_logger;

//XBEE interrupt, recieved new message

void CreateLocationMessage()
{
    if(AutonomousEnvironment::isRunning) {
        Logger::Log("<<<Creating location message>>>");
        LocationMessage* new_message = new LocationMessage();
        MessageQueue::EnQueue(new_message);
    }
}

void CreateControlMessage()
{
    
    if(AutonomousEnvironment::isRunning) {
        Logger::Log("<<<Creating Control message>>>");
        ControlMessage* new_message = new ControlMessage();
        new_message->Process();
        ControlValidator::ResetTimer();
        delete new_message;
    }
    //ControlQueue::EnQueue(new_message); //for future use

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
    ControlValidator::Initialize();
    LogButton.fall(&ToggleLogger);
    bool is_first_control_message=true;

    //Test for dest
    AutonomousEnvironment::destLocation=Location(15,15);//test destination

    message_location_timer_interrupt.attach(&CreateLocationMessage, TIME_CREATE_LOCATION_MESSAGE);   //every TimeCreateLocationMessage in sec
    message_control_timer_interrupt.attach(&CreateControlMessage, TIME_CREATE_CONTROL_MESSAGE);      //every TimeCreateControlMessage in sec
    WDG_timer_interrupt.attach(&Watchdog::Count,WDG_TIMER );                                         //every WDG_TIMER in sec
    //Log_timer_interrupt.attach(&Logger::PrintLogMessage,LOG_TIMER );


    //thread_logger.start(Logger::PrintLogMessage); //thread for logger



    //  set WDG count to 0
    Watchdog::kick();

    //Test need to recieve start message
    AutonomousEnvironment::isStart = true;

    while(AutonomousEnvironment::isRunning) {
        Logger::PrintLogMessage();
        if(AutonomousEnvironment::isStart ) {
            if(!MessageQueue::flag_is_empty) {
                Logger::Log("Poping message from queue");
                Message* current_message = MessageQueue::DeQueue();

                if(current_message!=NULL) {                                                           //check if queue was empty
                    //Logger::Log("currently preccessing message type ",current_message.m_messageType);
                    current_message->Process();
                    delete current_message;
                } else
                    Logger::Log("NULL MESSAGE");
            }
            /*  //for future use
                        if(!ControlQueue::flag_is_empty) {
                            Message* current_control_message = ControlQueue::DeQueue();

                            if(current_control_message!=NULL) {                                                               //check if queue was empty
                                //Logger::Log("currently preccessing message type ",current_control_message.m_messageType);
                                current_control_message->Process();
                                if(is_first_control_message) {
                                    is_first_control_message=false;
                                    Watchdog::kick();
                                } else
                                    //AutonomousEnvironment::isRunning=Watchdog::kick();
                                    Watchdog::kick();
                                delete current_control_message;

                            } else
                                Logger::Log("NULL MESSAGE");
                        }
            */

        }
    }


//Stopping the car and freeing all the alocated objects
    Message* current_message= new StopMessage();
    current_message->Process();
    return 0;
}







