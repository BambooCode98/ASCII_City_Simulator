#include <ncurses.h>
#include <iostream>



class Map{
  int _sx, _sy;
  WINDOW* _win;

  public:
    Map(int sy, int sx, WINDOW* win);
    void createMap();

  
};