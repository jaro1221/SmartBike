// DataModel.h

#ifndef _DATAMODEL_h
#define _DATAMODEL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <RTClib.h>
#include <DallasTemperature.h>
#include "Stopwatch.h"


class DataModel
{
public:
	DataModel(RTC_DS1307 * rtc_p);
	DataModel(RTC_DS1307 * rtc_p, DallasTemperature * term_p);

	DateTime GetRTCTime();
	float GetTerm();
	int GetStopwatchValue();

private:
	RTC_DS1307 * _RTC;
	DallasTemperature * _Term;

	Stopwatch _Stopwatch;

};

#endif
