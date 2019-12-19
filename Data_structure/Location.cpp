#include "Location.h"
#include <math.h>


/*
The Location module

	Get Set functions for location
	Params: x, y

*/
	


Location::Location(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Location::GetX()
{
	return x;
}
double Location::GetY()
{
	return y;
}
