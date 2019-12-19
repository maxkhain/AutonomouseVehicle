#pragma once
#ifndef _Location_H    /* Guard against multiple inclusion */
#define _Location_H  




class Location {

private:

	double x, y;

public:

	Location(double x, double y);	
	double GetX();
	double GetY();
	

};

#endif 

