#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>

// #include "screen.h"
#include "game.h"



using namespace std;


int main() {
  initscr();

  Game newGame;

  newGame.GameLoop();
 
  endwin();

  return 0;

} 
