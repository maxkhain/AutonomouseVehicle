#pragma once
#ifndef _LOGGER_H    /* Guard against multiple inclusion */
#define _LOGGER_H

#include "mbed.h"
#include <iostream>
#include <string>
#include <sstream>
#include "AutonomousEnvironment.h"
#include "Location.h"
#include "rtos.h"


/**Logger

@note This is a global logger that outputs to serial

@params


*/

#define BUFFER_SIZE 256

static Serial pc(SERIAL_TX, SERIAL_RX);
//static Serial pc(USBTX, USBRX);

template <typename T>
string NumberToString(T pNumber)
{
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}

typedef struct {
    char log_string[BUFFER_SIZE];   /* log string */    
} message_t;


class Logger
{


private:

  
    static int Sec ;
    static uint32_t mSec ;
    static uint32_t uSec ;
    static int counter; 
    

public:
    static Timer timer;
    
    static bool flag_is_empty;

    static void Initialize();
    
    //prints string
    static void Log(string for_print);
    
    //prints a double and a string
    static void Log(string for_print,double double_for_print);
    
    //prints a Location and a string
    static void Log(string for_print,Location location_for_print);
    
    //prints an int and a string
    static void Log(string for_print,int int_for_print);
    static void PrintLogMessage();
};

//a function that turns a number of micro sec to time format of ss:ms ms ms:micros micros micros' no spaces
string NumberToStringTime(int pNumber);

#endif
