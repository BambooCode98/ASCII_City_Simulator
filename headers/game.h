#pragma once
#include <iostream>
// #include "player.h"

// class Player;

class Game{
  public:
    Game();
    void GameLoop();
    void setQuit(int quit);
    // void runCity(Player player);



  private:
    int _quit;


};