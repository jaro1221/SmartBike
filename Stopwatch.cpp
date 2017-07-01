// 
// 
// 

#include "Stopwatch.h"

Stopwatch::Stopwatch()
{
	isRunning = true;
}

void Stopwatch::Start()
{
	isRunning = true;
	startMillis = (int)millis();
}

void Stopwatch::Stop()
{
	isRunning = false;
	valueLastMillis = valueMillis;
}

void Stopwatch::Run()
{
	if (isRunning)
	{
		valueMillis = millis() - startMillis + valueLastMillis;
	}
}

void Stopwatch::Reset()
{
	valueMillis = 0;
	valueLastMillis = 0;
	startMillis = 0;
}
