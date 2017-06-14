#include <Arduino.h>
#line 1 "c:\\Users\\imn1oy\\Documents\\Arduino\\sketchbook\\SmartBike\\SmartBike.ino"
#line 1 "c:\\Users\\imn1oy\\Documents\\Arduino\\sketchbook\\SmartBike\\SmartBike.ino"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "libs\Interface.h"
#include "libs\Interface.cpp"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Interface Ui;

void setup()
{
    RunComputer();

    display.setTextSize(1);
    display.setTextColor(WHITE);
}

void loop()
{
    drawInterface();

    int time1 = millis() / 1000;
    int time2 = (millis() / 10);
    int time3 = time2 - (time1 * 100);
    display.setCursor(2, 11);
    display.print(time1);
    display.print(".");
    if (time3 == 0)
        display.print("00");
    else
        display.print(time3);
        display.setCursor(2, 2);
        display.print("Temperature");
        display.setCursor(96, 2);
        display.print("22:38");
    display.display();
    delay(10);
    display.clearDisplay();
}

void RunComputer()
{
    InitLEDDisplay();
}

void InitLEDDisplay()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    delay(1000);
    display.clearDisplay();
}

void drawInterface()
{
    drawLayout();
}

void drawLayout()
{
    drawLines();
}

void drawLines()
{
    for(int i = 0; i < NUMBEROF_LINES; i++)
        display.drawLine(Ui.Lines[i].startPoint_X, Ui.Lines[i].startPoint_Y, Ui.Lines[i].endPoint_X, Ui.Lines[i].endPoint_Y, WHITE);
}
