#include "Logger.h"

Timer Logger::timer;
int Logger::Sec=0;
uint32_t Logger::mSec =0;
uint32_t Logger::uSec =0;

void Logger::Initialize()
{
    pc.printf("Starting Logger");
    timer.start();
    Sec = 0;
    mSec = 0;
    uSec = 0;
}

void Logger::Log(string for_print)
{
    if( AutonomousEnvironment::isLogging) {
        uSec = timer.read_us();        
        mSec = (uSec/1000)%1000;
        Sec = uSec/1000000;
        uSec = timer.read_us()%1000;
        string forPrintTimer =  NumberToString(Sec) + ":" + NumberToStringTime(mSec) + ":" + NumberToStringTime(uSec);
        pc.printf("%s %s \n", forPrintTimer.c_str(),for_print.c_str());
    }
}

string NumberToStringTime(int pNumber)//need to check this***
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