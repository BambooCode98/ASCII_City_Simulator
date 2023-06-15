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
  wmove(_win,_y,_x);


  init_pair(1,COLOR_RED, COLOR_WHITE);
  init_pair(2,COLOR_BLUE, COLOR_WHITE);
  init_pair(3,COLOR_YELLOW, COLOR_WHITE);
  init_color(11,400,400,400);
  init_color(12,100,100,100);
  init_pair(5,COLOR_WHITE, 11);
 
  // mvwaddch(_win,_y+1,_x+1,'.');

  _key = wgetch(_win);
  // mvprintw(LINES/1.1,COLS/2,"%d",_key);
  if(_key==KEY_UP) {
    _y--;
    checkForWalls("up");
    // mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_DOWN) {
    _y++;
    checkForWalls("down");
    // mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_RIGHT) {
    _x++;
    checkForWalls("right");

    // mvwaddch(_win,_y,_x,'.');
  } else if(_key==KEY_LEFT) {
    _x--;
    checkForWalls("left");

    // mvwaddch(_win,_y,_x,'.');
  } else if(_key == 'r' && _envSafe && _canBuild) {

    wattron(_win,COLOR_PAIR(1));
    mvwaddch(_win,_y,_x,'R');
    wattroff(_win,COLOR_PAIR(1));

  } else if(_key == 'c' && _envSafe && _canBuild) {

    wattron(_win,COLOR_PAIR(2));
    mvwaddch(_win,_y,_x,'C');
    wattroff(_win,COLOR_PAIR(2));

  } else if(_key == 'i' && _envSafe && _canBuild) {

    wattron(_win,COLOR_PAIR(3));
    mvwaddch(_win,_y,_x,'I');
    wattroff(_win,COLOR_PAIR(3));

  } else if(_key == '-' && _canBuild) {

    wattron(_win,COLOR_PAIR(5));
    mvwaddch(_win,_y,_x,'-');
    wattroff(_win,COLOR_PAIR(5));

  }
  // mvwprintw(_win, LINES/2, COLS/2,"%c",char(_key));
  wrefresh(_win);
  return _key;
}



bool Player::checkforObjs() {

  // wmove(_win,_x,_y);
  int obj = mvwinch(_win,_y,_x) & A_CHARTEXT;
  // mvprintw(LINES/1.3,COLS/1.3,"%d  want: %d", obj, 82);
  _canBuild = true;
  // _canDelete = false;
  switch(obj) {
    case int('R'):
      _canBuild = false;
      // _canDelete = true;
      break;
    case int('C'):
      _canBuild = false;
      break;
    case int('I'):
      _canBuild = false;
      break;
    case int('~'):
      _canBuild = false;
      break;
    case int('-'):
      _canBuild = false;
    break;
  }
  wrefresh(_win);
  return _canBuild;
}

void Player::checkForWalls(std::string dir) {
  // getCoordinates();
  int walls = mvwinch(_win,_y,_x) & A_CHARTEXT;
  // wprintw(_curwin,"%d", wall);
  // mvwprintw(_curwin,_yMax/1.3,_xMax/1.5, "_y: %d _x: %d", _y, _x);

  if(dir == "down" && walls == '#') {
    _y--;
    // _y_coord--;
  } else if(dir == "up" && walls == '#') {
    _y++;
    // _y_coord++;
  } else if(dir == "right" && walls == '#') {
    _x--;
    // _x_coord--;
  } else if(dir == "left" && walls == '#') {
    _x++;
    // _x_coord++;
  }
}

bool Player::checkEnv() {
  
  int env = mvwinch(_win,_y,_x) & A_CHARTEXT;

  if(env=='~') {
    _envSafe = false;
  } else {
    _envSafe = true;
  }

  return _envSafe;
}

int Player::canDelete() {
  int toDelete = 0;

  int del = mvwinch(_win,_y,_x) & A_CHARTEXT;
  // _okToDel = d;

  if(del==int('R')) {
    toDelete = 'R';
  } else if (del=='C') {
    toDelete = 'C';
  } else if (del=='I') {
    toDelete = 'I';
  } else if(del=='-') {
    toDelete = del;
  }

  // mvprintw(LINES-7,COLS/2+1,"%d %d", toDelete, del);


  return toDelete;

}

void Player::clear() {
  wattron(_win,COLOR_PAIR(10));
  mvwaddch(_win,_y,_x,' ');
  wattroff(_win,COLOR_PAIR(10));
}