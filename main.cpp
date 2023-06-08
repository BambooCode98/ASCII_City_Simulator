#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>

#include "screen.h"



using namespace std;


int main() {
  Screen::createScreen();
  WINDOW* display = newwin(LINES/2,COLS/2,0,0);
  box(display,0,0);
  refresh();

  // wprintw(display,"printing...");

  wrefresh(display);
  // char tmp;
  // mvwprintw(display,LINES/1.5,COLS/1.5,"Enter any key to conitinue...");
  // cin>>tmp;

  delwin(display);
  Screen::deleteScreen();
  // cout << "hi\n";
  return 0;

} 
