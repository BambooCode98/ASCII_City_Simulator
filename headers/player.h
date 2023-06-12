#include <iostream>

#include <ncurses.h>




class Player{
  public:
    Player(WINDOW* win, int x, int y);
    int moveCursor();



  private:
    int _x;
    int _y;
    int _key;
    WINDOW* _win;


};