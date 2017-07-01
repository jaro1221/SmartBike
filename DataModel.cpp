// 
// 
// 

#include "DataModel.h"


DataModel::DataModel(RTC_DS1307 * rtc_p)
{
	_RTC = rtc_p;
}

DataModel::DataModel(RTC_DS1307 * rtc_p, DallasTemperature * term_p)
{
	_RTC = rtc_p;
	_Term = term_p;
	_Term->setCheckForConversion(false);
	_Term->setWaitForConversion(false);
}

DateTime DataModel::GetRTCTime()
{
	// setting current time&date
	//
	//_RTC->adjust(DateTime(__DATE__, __TIME__));

	DateTime RTCTime = _RTC->now();

	return RTCTime;
}

float DataModel::GetTerm()
{
	_Term->requestTemperatures();
	return _Term->getTempCByIndex(0);
}

int DataModel::GetStopwatchValue()
{
	_Stopwatch.Run();
	return _Stopwatch.valueMillis;
}


