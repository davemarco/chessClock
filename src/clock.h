#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


 class Clock {
   private:
    int address;

   public:
    Adafruit_7segment display;  //Sevseg display
    int minutes;
    int seconds;

    //contructor
    Clock(int address);

    //sets I2C address for display
    void begin();

    static void decrementTime();

    void addTime(int s);
 };
