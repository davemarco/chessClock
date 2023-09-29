/*
David Marcovitch
Start Date: 05/10/2022
Main file for chess clock
 */

#include "clock.h"
#include "button.h"
#include "buttonResponse.h"
#include <TimerOne.h>


#define DISPLAY1_ADDRESS  0x70
#define DISPLAY2_ADDRESS  0x71

/*********GLOBAL VARIABLE DECLARATIONS**************/
Clock player1Clock(DISPLAY1_ADDRESS);
Clock player2Clock(DISPLAY2_ADDRESS);
Button player1Button(2);
Button player2Button(3);
bool player1_turn = NULL;
int increment = 5;
bool gamePaused = true;
bool gameOver = false;


void setup() {
  player1Clock.display.begin(DISPLAY1_ADDRESS);
  player2Clock.display.begin(DISPLAY2_ADDRESS);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Clock::decrementTime);
  Serial.begin(9600);
  Serial.print("Clock Initialized /n");
}

void loop() {

  player1Clock.display.print(player1Clock.minutes*100 + player1Clock.seconds);
  player2Clock.display.print(player2Clock.minutes*100 + player2Clock.seconds);
  player1Clock.display.writeDisplay();
  player2Clock.display.writeDisplay();

  player1Button.checkForPush(&changeTurn);
  player2Button.checkForPush(&changeTurn);

}
