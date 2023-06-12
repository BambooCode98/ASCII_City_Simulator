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
    void runCity(Player &player);
    void updateSim(Simulation &simulate);



  private:
    int _quit;
    int _p = 0;
    // float _price = 5000;
    int _price = 5000;
    std::vector<Building*> _buildings;
    WINDOW* _cityWin;


};