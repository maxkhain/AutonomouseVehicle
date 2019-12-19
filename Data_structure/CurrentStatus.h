#pragma once
#ifndef _CURRENTSTATUS_H    /* Guard against multiple inclusion */
#define _CURRENTSTATUS_H  

class Status {
private:
	double angle;
	double speed;


public:
	Status(double speed, double angle)
	{
		this->speed = speed;
		this->angle = angle;
	}
	double GetCurrentSpeed();
	double GetCurrentAngle();
	void SetCurrentStats(double current_speed, double current_angle);
	void SetCurrentSpeed(double new_speed);
	void SetCurrentAngle(double new_angle);
};


#endif 
