#include <iostream>

#include <ncurses.h>




class Player{
  public:
    Player(WINDOW* win);
    int moveCursor();



  private:
    int _x = 1;
    int _y = 1;
    int _key;
    WINDOW* _win;


};