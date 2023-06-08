#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>


#include "screen.h"

Screen::Screen() {};

void Screen::createScreen() {
  initscr();
  cbreak();
  noecho();
  clear();
  curs_set(0);
}


void Screen::deleteScreen() {
  endwin();
}


