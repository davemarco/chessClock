#include "globals.h"
#include "button.h"

void changeTurn(Button* player) {
  if (gameOver) {return;}
    //start game on first button press
  if (gamePaused == true) {
    gamePaused = !gamePaused;
    if (player == &player1Button) {player1_turn = true;}
    if (player == &player2Button) {player1_turn = false;}
    }
  //only toggle if time if it is player's turn
  if ((player == &player1Button && player1_turn) || (player == &player2Button && !player1_turn)) {
  player1_turn = !player1_turn;
  if (!player1_turn) {player1Clock.addTime(increment);}
  if (player1_turn) {player2Clock.addTime(increment);}
  }
}

void pause() {
  gamePaused = !gamePaused;
}

void player1() {player1_turn = true;gamePaused = false;}
void player2() {player1_turn = false;gamePaused = false;}
