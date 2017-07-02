// Stopwatch.h

#ifndef _STOPWATCH_h
#define _STOPWATCH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Stopwatch
{
public:
	Stopwatch();
	void Start();
	void Stop();
	void Reset();
	unsigned int valueMillis;
	void Run();
    unsigned int valueLastMillis;
	unsigned int startMillis;

	bool isRunning;

private:
	
	

	

};

#endif

