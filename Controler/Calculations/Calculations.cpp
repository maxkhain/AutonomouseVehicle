#include <math.h>
#include "Location.h"
#include "Calculations.h"
#include "AutonomousEnvironment.h"

//angle calculations in radian



double Calculations::CalculateAngleToDestination()
{
    Location current_location=AutonomousEnvironment::currentLocation;
    Location destination= AutonomousEnvironment::destLocation;
    double delta_y=destination.GetY()-current_location.GetY();
    double delta_x=destination.GetX()-current_location.GetX();
    return atan2(delta_y,delta_x);
}
double Calculations::CalculateDistance()
{
    Location current_location=AutonomousEnvironment::currentLocation;
    Location destination= AutonomousEnvironment::destLocation;
    double x_distance = destination.GetX() - current_location.GetX();
    double y_distance = destination.GetY() - current_location.GetY();
    double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
    Logger::Log("Distance to dest is: ", distance);
    return distance;
}
double Calculations::CalculateSpeed(double distance)
{
    double current_speed=AutonomousEnvironment::currentStatus.GetCurrentSpeed();
    double velocity;
    //speed control
    if(distance<(deaccelarate_time*max_speed)) { // close to destination- diaccelaration        
        if(distance < 0.1*(deaccelarate_time*max_speed))
            velocity=0;
        else
            velocity=max_speed*(distance/(deaccelarate_time*max_speed));
    }

    else { // close to start- accelaration
        double new_speed =current_speed+(max_speed/(accelarate_time));
        if(new_speed <max_speed)
            velocity = current_speed+(max_speed/(accelarate_time));
        else
            velocity=max_speed;
    }
    //Logger::Log(" Current speed is: ", velocity);
    //AutonomousEnvironment::currentStatus.SetCurrentSpeed(velocity);
    return velocity;

}

void Calculations::CalculateNewLocation()
{
    double velocity=AutonomousEnvironment::currentStatus.GetCurrentSpeed();
    double angle = AutonomousEnvironment::currentStatus.GetCurrentAngle();
    double x_location = AutonomousEnvironment::currentLocation.GetX()+(velocity*cos(angle)*(TIME_CREATE_CONTROL_MESSAGE));
    double y_location = AutonomousEnvironment::currentLocation.GetY()+(velocity*sin(angle)*(TIME_CREATE_CONTROL_MESSAGE));
    AutonomousEnvironment::currentLocation = Location(x_location,y_location);
}


