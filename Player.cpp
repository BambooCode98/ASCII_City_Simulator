#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>
#include "player.h"
#include "buildings.h"

Player::Player(WINDOW* win,int x, int y) {
  _win = win;
  _x = x;
  _y = y;
}

int Player::moveCursor() {
 
  // mvwaddch(_win,_y+1,_x+1,'.');

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
  } else if(_key == 'r') {
    mvwaddch(_win,_y,_x,'R');
  } else if(_key == 'c') {
    mvwaddch(_win,_y,_x,'C');
  } else if(_key == 'i') {
    mvwaddch(_win,_y,_x,'I');
  }
  // mvwprintw(_win, LINES/2, COLS/2,"%c",char(_key));
  wrefresh(_win);
  return _key;
}