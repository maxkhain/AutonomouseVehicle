#pragma once
#ifndef _Location_H    /* Guard against multiple inclusion */
#define _Location_H  

/**Location

@param <x>  
@param <y>



*/



class Location {

private:

	double x, y;

public:

	Location(double x, double y);	
	double GetX();
	double GetY();
	

};

#endif 

