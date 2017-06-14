#ifndef Interface_h
#define Interface_h

#include <Arduino.h>

#define NUMBEROF_LINES 4
class Interface
{
  public:
    Interface();
    struct Layout_lines
    {
        int startPoint_X;
        int startPoint_Y;
        int endPoint_X;
        int endPoint_Y;
    } Lines[NUMBEROF_LINES] = {{0, 0, 127, 0}, {0, 0, 0, 63}, {0, 63, 127, 63}, {127, 63, 127, 0}};
    
    
  private:
    
    
};

class Menu
{
    public:
        Menu();

    private:

};

struct MenuEntry
{

};

#endif