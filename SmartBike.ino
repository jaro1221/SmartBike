//#include <RTClib.h>
#include "Stopwatch.h"
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <OneWire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Interface.h"
#include "DataModel.h"

#define OLED_RESET 4
#define ONEWIRE_PORT 2

int buttonPort = A1;

Adafruit_SSD1306 display(OLED_RESET);
RTC_DS1307 RTC;
OneWire oneWire(ONEWIRE_PORT);
DallasTemperature Term(&oneWire);

DataModel dataModel(&RTC, &Term);
Interface ui(&display, &dataModel);


void setup()
{
    Serial.begin(9600);
	InitDevices();
	pinMode(buttonPort, INPUT);
}

void loop()
{
	ui.drawInterface();
    display.display();
    delay(1);
    display.clearDisplay();
}


void InitDevices()
{
	// OLED
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.display();
	delay(1000);
	display.clearDisplay();

	// RTC
	Wire.begin();
	RTC.begin();

	// DS18B20
	Term.begin();
}
