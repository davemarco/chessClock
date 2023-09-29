#pragma once

#include <Arduino.h>

class Button {
  private:

  public:
  int pin;
  int buttonState;
  int reading;
  int lastButtonState = LOW;
  // the following variables are unsigned longs because the time, measured in
  // milliseconds, will quickly become a bigger number than can be stored in an int.
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time;

  //contructor
  Button(int p);

  //Checks if button pushed, if so change player turn
  void checkForPush(void (*f)(Button* p));

  void changeTurn();
};