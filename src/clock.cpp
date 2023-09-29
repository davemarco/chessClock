/*
David Marco
Start Date: 05/10/2022
Clock class
 */

#include "clock.h"
#include "globals.h"

//Create a new clock with given I2C address
Clock::Clock (int a) {
   //create a new seven segement display
   display = Adafruit_7segment();
   address = a;
   minutes = 5;
   seconds = 0;
 }

void Clock::begin () {
  display.begin(address);
}

void Clock::decrementTime() {
  if (gamePaused) {return;}

  //Stop clock if out of time
  if (player1Clock.seconds + player1Clock.minutes == 0 || player2Clock.seconds + player2Clock.minutes == 0) {
    gameOver = true;
    return;
  }


  if (player1_turn) {
  //reduce player 1 time
  if (player1Clock.seconds == 0) {
    player1Clock.minutes--;
    player1Clock.seconds = 59;}
  else {player1Clock.seconds--;}}
  //reduce player 2 time
  else {
    if (player2Clock.seconds == 0) {
    player2Clock.minutes--;
    player2Clock.seconds = 59;}
    else {player2Clock.seconds--;}}
}

void Clock::addTime(int s) {
  if ((seconds + s) > 59) {minutes++; seconds = seconds + s - 60;}
  else {seconds = seconds + s;}
}




