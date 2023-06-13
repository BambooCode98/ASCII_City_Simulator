#include <iostream>
#include <string>
#include <ncurses.h>




class Player{
  public:
    Player(WINDOW* win, int x, int y);
    int moveCursor();
    bool checkforObjs();
    void checkForWalls(std::string dir);
    bool checkEnv();



  private:
    int _x;
    int _y;
    int _key;
    WINDOW* _win;
    bool _envSafe = true;



};