#pragma once
#ifndef _LOGGER_H    /* Guard against multiple inclusion */
#define _LOGGER_H

#include "mbed.h"
#include <iostream>
#include <string>
#include <sstream>
#include "AutonomousEnvironment.h"
#include "Location.h"

static Serial pc(SERIAL_TX, SERIAL_RX);
//static Serial pc(USBTX, USBRX);

template <typename T>
string NumberToString(T pNumber)
{
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}




class Logger
{


private:
    static Timer timer;
    static int Sec ;
    static uint32_t mSec ;
    static uint32_t uSec ;

public:
    static void Initialize();
    static void Log(string for_print);
    static void Log(string for_print,double double_for_print);
    static void Log(string for_print,Location location_for_print);
    static void Log(string for_print,int int_for_print);
};

string NumberToStringTime(int pNumber);
#endif
