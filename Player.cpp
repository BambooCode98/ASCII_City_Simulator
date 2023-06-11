#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>
#include "player.h"

Player::Player(WINDOW* win) {
  _win = win;
}

int Player::moveCursor() {
 
  mvwaddch(_win,_y,_x,'.');

  _key = wgetch(_win);
  if(_key==KEY_UP) {
    _y--;
    mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_DOWN) {
    _y++;
    mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_RIGHT) {
    _x++;
    mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_LEFT) {
    _x--;
    mvwaddch(_win,_y,_x,'.');
  }
  // mvwprintw(_win, LINES/2, COLS/2,"%c",char(_key));
  wrefresh(_win);
  return _key;
}