#include "Logger.h"

Timer Logger::timer;
int Logger::Sec=0;
uint32_t Logger::mSec =0;
uint32_t Logger::uSec =0;
int Logger::counter=0;
bool Logger::flag_is_empty = true;
Queue<message_t, 64> log_queue;
MemoryPool<message_t, 64> mpool;


string for_print;
string forPrintTimer;

void Logger::PrintLogMessage()
{

    if(AutonomousEnvironment::isLogging) {
        osEvent evt = log_queue.get();
        if (evt.status == osEventMessage) {            
            message_t* message=(message_t*)evt.value.p;
            for_print = message->log_string;
            pc.printf("%s", for_print.c_str());
            free(message);
            counter--;
            if(counter==0)
                flag_is_empty = true;
        }

    }
}



void Logger::Initialize()
{
    //pc.printf("Starting Logger\n");
    timer.start();
    Sec = 0;
    mSec = 0;
    uSec = 0;
    counter=0;
    flag_is_empty=true;
}

void Logger::Log(string for_print)
{
    if( AutonomousEnvironment::isLogging) {        
        message_t *message_for_enqueue = new message_t;; //= mpool.alloc();
        if(message_for_enqueue==NULL) {
            pc.printf("NULL alloc\n");
            return;
        }
        //for future use
        uSec = timer.read_us();
        mSec = (uSec/1000)%1000;
        Sec = uSec/1000000;
        uSec = timer.read_us()%1000;
        forPrintTimer =   NumberToString(Sec) + ":" + NumberToStringTime(mSec) + ":" + NumberToStringTime(uSec)+": \0";
        string tmp_for_print = forPrintTimer+ " " +for_print+"\n";
        //message_t* message_for_enqueue = new message_t;
        strcpy(message_for_enqueue->log_string,tmp_for_print.c_str());
        //pc.printf("%s", message_pointer_for_enqueue->log_string.c_str());
        log_queue.put(message_for_enqueue);
        counter++;
        flag_is_empty=false;
        //for future use
        //mpool.free(message_for_enqueue);
    }
}

string NumberToStringTime(int pNumber)
{
    ostringstream oOStrStream;
    if(pNumber<10)
        oOStrStream << "0"<<"0"<<pNumber;
    else if(pNumber<100)
        oOStrStream << "0"<<pNumber;
    else
        oOStrStream<<pNumber;
    return oOStrStream.str();
}

void Logger::Log(string for_print,double double_for_print)
{
    string forPrintCombined =  for_print + NumberToString(double_for_print);
    Logger::Log(forPrintCombined);
}

void Logger::Log(string for_print,int int_for_print)
{
    string forPrintCombined =  for_print + NumberToString(int_for_print);
    Logger::Log(forPrintCombined);
}

void Logger::Log(string for_print,Location location_for_print)
{
    string forPrintCombined =  for_print +"("+ NumberToString(location_for_print.GetX())+" | "+ NumberToString(location_for_print.GetY())+")";
    Logger::Log(forPrintCombined);
}