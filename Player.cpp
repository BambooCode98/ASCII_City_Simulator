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

  init_pair(1,COLOR_RED, COLOR_BLACK);
  init_pair(2,COLOR_BLUE, COLOR_BLACK);
  init_pair(3,COLOR_YELLOW, COLOR_BLACK);
 
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

    wattron(_win,COLOR_PAIR(1));
    mvwaddch(_win,_y,_x,'R');
    wattroff(_win,COLOR_PAIR(1));

  } else if(_key == 'c') {

    wattron(_win,COLOR_PAIR(2));
    mvwaddch(_win,_y,_x,'C');
    wattroff(_win,COLOR_PAIR(2));

  } else if(_key == 'i') {

    wattron(_win,COLOR_PAIR(3));
    mvwaddch(_win,_y,_x,'I');
    wattroff(_win,COLOR_PAIR(3));

  }
  // mvwprintw(_win, LINES/2, COLS/2,"%c",char(_key));
  wrefresh(_win);
  return _key;
}



void Player::checkforObjs() {

  init_pair(1,COLOR_RED, COLOR_BLACK);
  init_pair(2,COLOR_BLUE, COLOR_BLACK);
  init_pair(3,COLOR_YELLOW, COLOR_BLACK);

  int obj = winch(_win) & A_CHARTEXT;
  mvprintw(LINES/1.3,COLS/1.3,"%d  want: %d", obj, 82);
  switch(obj) {
    case int('R'):
      wattron(_win,COLOR_PAIR(1));
      mvwaddch(_win,_y,_x,'R');
      wattroff(_win,COLOR_PAIR(1));
      break;
    case int('C'):
      wattron(_win,COLOR_PAIR(3));
      mvwaddch(_win,_y,_x,'C');
      wattroff(_win,COLOR_PAIR(3));
      break;
    case int('I'):
      wattron(_win,COLOR_PAIR(3));
      mvwaddch(_win,_y,_x,'I');
      wattroff(_win,COLOR_PAIR(3));
      break;
  }
}
