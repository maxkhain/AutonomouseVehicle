#include "CurrentStatus.h"

/*
The CurrentStatus module

	Get Set functions for status
	Params: speed, angle

*/
	

/*
Checking the current status of the sensors

*/
double Status::GetCurrentSpeed()
{
	return speed;
}

/*
Listening to a request from the user
*/
double Status::GetCurrentAngle()
{
	return angle;
}
void Status::SetCurrentStats(double current_speed, double current_angle)
{
	speed = current_speed;
	angle = current_angle;
}

void Status::SetCurrentSpeed(double new_speed)
{
	speed = new_speed;
}

void Status::SetCurrentAngle(double new_angle)
{
	angle = new_angle;
}

