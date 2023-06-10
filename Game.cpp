#include <ncurses.h>
#include <iostream>

#include "game.h"
#include "screen.h"
#include "player.h"

Game::Game() {
  // _quit = quit;
}

void Game::setQuit(int quit) {
  _quit = quit;
}

void Game::GameLoop() {

  WINDOW* display = newwin(LINES,COLS,0,0);
  box(display,0,0);
  Screen::createScreen(display);
  refresh();

  //create player
  Player player(display);


  while(_quit != 'p') {
    player.moveCursor();
  }


  
  delwin(display);
}