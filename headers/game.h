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
    int _quit;
    int _p = 0;
    unsigned int _numR, _numC, _numI, _tBuilds;
    int _price = 5000;
    WINDOW* _cityWin;
    bool _rc = false;
    bool _cc = false;
    bool _ic = false;


};