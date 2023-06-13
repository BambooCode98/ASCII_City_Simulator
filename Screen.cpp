#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>


#include "screen.h"

Screen::Screen() {};

void Screen::createScreen(WINDOW *mainwin) {
  cbreak();
  noecho();
  clear();
  // nodelay(mainwin, true);
  keypad(mainwin,true);
  start_color();
  init_pair(1,COLOR_RED, COLOR_BLACK);
  init_pair(2,COLOR_BLUE, COLOR_BLACK);
  init_pair(3,COLOR_YELLOW, COLOR_BLACK);

  
  // curs_set();
}


void Screen::deleteScreen() {
}


