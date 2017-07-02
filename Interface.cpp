// 
// 
// 

#include "Interface.h"

Interface::Interface(Adafruit_SSD1306 * oled_p)
{
	_OLED = oled_p;
}

Interface::Interface(Adafruit_SSD1306 * oled_p, DataModel * data_p)
{
	_OLED = oled_p;
	_data = data_p;
}

void Interface::drawInterface()
{
	drawLayout();
	drawData();
}

void Interface::drawLayout()
{
	// frame
	//_OLED->drawLine(0, 0, 127, 0, WHITE);
	//_OLED->drawLine(0, 0, 0, 63, WHITE);
	//_OLED->drawLine(0, 63, 127, 63, WHITE);
	//_OLED->drawLine(127, 63, 127, 0, WHITE);
	_OLED->drawRoundRect(0, 0, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, 2, WHITE);

	// time separator
	_OLED->drawLine(95, 0, 95, 10, WHITE);

	// status separator
	_OLED->drawLine(0, 10, 127, 10, WHITE);
}

void Interface::drawData()
{
	//DateTime now = RTC.now();

	// text font
	_OLED->setTextSize(1);
	_OLED->setTextColor(WHITE);

	// module title
	_OLED->setCursor(2, 2);
	_OLED->print("Temperature");

	drawRTCTime();
	drawTermValue();

	// temperature
	
}

void Interface::drawRTCTime()
{
	
	_OLED->setCursor(97, 2);

	if ((_data->GetRTCTime().hour()) < 10)
		_OLED->print(" ");

	_OLED->print(_data->GetRTCTime().hour());

	_OLED->print(":");

	if ((_data->GetRTCTime().minute()) < 10)
		_OLED->print("0");

	_OLED->print(_data->GetRTCTime().minute());
}

void Interface::drawTermValue()
{
	//_OLED->setTextSize(2);
//	_OLED->setCursor(3, 37);
//	_OLED->print(_data->GetTerm());
//	_OLED->print("`C");
//	_OLED->print(_data->GetStopwatchValue());
   Serial.println(_data->GetTerm());
    Serial.println(_data->_Stopwatch.valueMillis);
    Serial.println(_data->_Stopwatch.valueLastMillis);
    Serial.println(_data->_Stopwatch.startMillis);
}
