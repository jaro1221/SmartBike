// Interface.h

#ifndef _INTERFACE_h
#define _INTERFACE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_SSD1306.h>
#include "DataModel.h"

class Interface
{
public:
	Interface(Adafruit_SSD1306 * oled_p);
	Interface(Adafruit_SSD1306 * oled_p, DataModel * data_p);

	void drawInterface();
	
private:

	Adafruit_SSD1306 * _OLED;
	DataModel * _data;
	
	void drawLayout();
	void drawData();

	void drawRTCTime();
	void drawTermValue();

};

#endif

