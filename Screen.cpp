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
  keypad(mainwin,true);
  // curs_set();
}


void Screen::deleteScreen() {
}


