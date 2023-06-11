#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "game.h"
#include "screen.h"
#include "player.h"
#include "simulation.h"

Game::Game() {
  // _quit = quit;
}

void Game::setQuit(int quit) {
  _quit = quit;
}

// auto now() {
//   return std::chrono::steady_clock::now();
// }

// auto awake() {
//   using std::chrono::operator""ms;
//   return now() + 1000ms;
// }
// void Game::runCity() {
  

//   refresh();
// }

void Game::GameLoop() {

  //create city view
  WINDOW* city = newwin(LINES,COLS/2,0,0);
  box(city,0,0);
  Screen::createScreen(city);
  refresh();

  //create city stats view
  WINDOW* stats = newwin(LINES/4,COLS/3,0,COLS/2+5);
  box(stats,0,0);
  Screen::createScreen(stats);
  refresh();




  //create player
  Player player(city);
  Simulation simulate(stats);

  int m = 5;

  while(_quit != 'p') {
    _quit = player.moveCursor();

    // std::thread t1(&Game::runCity,this,player);
    m+=1;
    simulate.update(m);

  }

  


  


  delwin(city);
  delwin(stats);
}