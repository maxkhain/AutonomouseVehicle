#include "GPSApi.h"

Location GPSApi::GetGPSLocation()
    {
        return AutonomousEnvironment::currentLocation;
    }

// Here's a snippet showing how this API can be used. The handler gets invoked
// from thread context--i.e. from the main application.
//
//      void handleGPSData(const LocationUpdateParams_t *newLocation) {
//          ...
//      }
//
//      GPSProvider gps;
//
//      gps.setPowerMode(LOW_POWER);
//      gps.onLocationUpdate(handleGPSData);
//
//      gps.reset();
//      gps.start();
//
//      while (true) {
//          /* purely optional */
//          static bool printedDeviceInfo = false;
//          if (!printedDeviceInfo && gps.haveDeviceInfo()) {
//              printf("%s", gps.getDeviceInfo());
//              printedDeviceInfo = true;
//          }
//
//          /* Main message processing activity; location callbacks are called
//           * as a result of message processing. */
//          gps.process();
//          /* sleep(); */
//
//          if (/* at some point in the future */) {
//              break;
//          }
//      }
//      gps.stop();
//