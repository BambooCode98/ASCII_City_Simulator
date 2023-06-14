#pragma once
#include <iostream>
#include <ncurses.h>
#include <vector>
// #include "player.h"

class Player;
class Simulation;
class Building;

class Game{
  public:
    Game();
    void GameLoop();
    void setQuit(int quit);
    void runCity(Player &player,Simulation &simulate);
    void updateSim(Simulation &simulate);



  private:
    int _quit = 0;
    int _p = 0;
    unsigned int _numR = 0, _numC = 0, _numI = 0, _tBuilds = 0;
    int _price = 5000;
    WINDOW* _cityWin;
    bool _rc = false;
    bool _cc = false;
    bool _ic = false;
    bool _okToBuild = true;
    bool _envSafe = true;
    int  _delete = 0;


};