#pragma once
#include <iostream>
// #include "player.h"

class Player;
class Simulation;

class Game{
  public:
    Game();
    void GameLoop();
    void setQuit(int quit);
    void runCity(Player &player);
    void updateSim(Simulation &simulate);



  private:
    int _quit;


};