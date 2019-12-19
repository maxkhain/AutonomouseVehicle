
#pragma once
#ifndef _GPSAPI_H    /* Guard against multiple inclusion */
#define _GPSAPI_H

#include "Location.h"
#include "AutonomousEnvironment.h"
/*
#include "Teseo.h"
#include "GPSProvider.h"
#include "geofence_config.h"
*/
class GPSApi {
public:
    static Location GetGPSLocation();
    
};

#endif
