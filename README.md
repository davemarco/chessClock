I became interested chess and built a home-made chess clock with some spare time. 
Clock is implemented in C++ and runs on an Arduino.

## Overview
Arduino keeps two timers and sends remaining player time to Adafruit displays over I2C. 
Buttons send signals to Arduino to change player turn and add increment.
Buttons are debounced and each have a pull down resistor.

## Demo
https://github.com/davemarco/chessClock/assets/83603688/48da3e57-226a-41ae-a6be-07e6e126f5b0

## Files
ChessClock.ino - contains main loop and setup
Button.cpp - button class responsible for debouncing
Clock.cpp - clock class resonsible for keeping player time
buttonResponse.cpp - callback function for changing player turn on button press

## Hardware
1 x Adafruit METRO 328 (Arduino)
2 x Adafruit 1.2" 4-Digit 7-Segment Display w/I2C Backpack
2 x 12mm Square Tactile Button Switch
2 x 100 ohm resistors

## Circuit Diagram
![Circuit Diagram](https://github.com/davemarco/chessClock/assets/83603688/c4d1f427-f712-413e-a163-3df70f601181)




