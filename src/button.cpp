/*
David Marco
Start Date: 06/11/2022
Button class
 */

#include "button.h"
#include "globals.h"

//Create a new clock with given I2C address
Button::Button (int p) {
  pin = p;
}

void Button::checkForPush(void (*f)(Button* p)) {

  int reading = digitalRead(pin);

  // reset the debouncing timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // whatever the reading is at, it's been there for longer than the debounce
  // delay, so take it as the actual current state:
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      // only toggle if the new button state is HIGH
      if (buttonState == HIGH) {
       f(this);
      }
    }
  }
  lastButtonState = reading;
}




