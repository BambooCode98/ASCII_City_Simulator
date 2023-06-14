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
    int canDelete();
    void clear();



  private:
    int _x;
    int _y;
    int _key;
    WINDOW* _win;
    bool _envSafe = true;
    bool _canBuild = true;
    bool _okToDel = false;





};