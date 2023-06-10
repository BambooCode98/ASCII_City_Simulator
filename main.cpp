#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>

#include "screen.h"



using namespace std;


int main() {
  initscr();

  WINDOW* display = newwin(LINES,COLS,0,0);
  box(display,0,0);
  Screen::createScreen(display);
  refresh();
  int key;
  int y = 1;
  int x = 1;
  mvwaddch(display,y,x,'.');
  // wprintw(display,"printing...");
  while(key != 'p'){
    key = wgetch(display);
    if(key==KEY_UP) {
      y--;
      mvwaddch(display,y,x,'.');
    } else if(key==KEY_DOWN) {
      y++;
      mvwaddch(display,y,x,'.');
    } else if(key==KEY_RIGHT) {
      x++;
      mvwaddch(display,y,x,'.');
    } else if(key==KEY_LEFT) {
      x--;
      mvwaddch(display,y,x,'.');
    }
    mvwprintw(display, LINES/2, COLS/2,"%c",char(key));
    wrefresh(display);

  }
  // char tmp;
  // mvwprintw(display,LINES/1.5,COLS/1.5,"Enter any key to conitinue...");
  // cin>>tmp;

  delwin(display);
  endwin();

  // cout << "hi\n";
  return 0;

} 
