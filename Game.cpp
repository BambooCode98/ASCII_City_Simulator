#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "game.h"
#include "screen.h"
#include "player.h"
#include "simulation.h"
#include "buildings.h"


Game::Game() {
  // _quit = quit;
}

void Game::setQuit(int quit) {
  _quit = quit;
}

void Game::runCity(Player &player) {
  while(_quit != 'p') {
    _quit = player.moveCursor();
    
    if(_quit == 'r') {
      Building res("res", 1, 25, 500);
      // simulate.getCost(res.getCost());
      if(_price <= 0) {
        _price;
      } else {
        _price -= res.getCost();
      }
      mvprintw(LINES/2,COLS/2,"Created a residential building.");
      _buildings.push_back(&res);
    } else if (_quit == 'c') {
      Building com("com", 10, 0, 750);
      // simulate.getCost(res.getCost());
      if(_price <= 0) {
        _price;
      } else {
        _price -= com.getCost();
      }
      mvprintw(LINES/2,COLS/2,"Created a commercial building.");
      _buildings.push_back(&com);
    } else if (_quit == 'i') {
      Building ind("ind", 25, 0, 1000);
      // simulate.getCost(res.getCost());
      if(_price <= 0) {
        _price;
      } else {
        _price -= ind.getCost();
      }
      mvprintw(LINES/2,COLS/2,"Created an industrial building.");
      _buildings.push_back(&ind);
    }
    for(int i = 0; i < _buildings.size(); i++) {
      // mvprintw(LINES/2+5+i,COLS/2,"%s revenue: %d","obj", _buildings[i]->getrev());
    }

    refresh();
  }
  

}

void Game::updateSim(Simulation &simulate) {
  // _price = 5;
  // int p = 0;
  // for(int i = 0; i < _buildings.size(); i++) {
  //     // _price+=_buildings[i]->getrev();
  //     _p+=_buildings[i]->getpop();
  //   }

  while(_quit != 'p') {
    // int popBefore = _p;
    // int popAfter;
    
    for(int i = 0; i < _buildings.size(); i++) {
      // _price+=_buildings[i]->getrev();
      // _p+=_buildings[i]->getpop();
      mvprintw(LINES/2+2+i,COLS/2,"%s",_buildings[i]->getType().c_str());
      // popAfter = _p;
      // if() {
      //   _p;
      // } else {
      //   _p+=_buildings[i]->getpop();

      // }
    }
    // m+=1;
    simulate.update(_price,_p);
    // m+=1;

    refresh();
  }
  

}

void Game::GameLoop() {

  //create city view
  WINDOW* city = newwin(LINES,COLS/2,0,0);
  _cityWin = city;
  box(city,0,0);
  Screen::createScreen(city);
  refresh();

  //create city stats view
  WINDOW* stats = newwin(LINES/4,COLS/3,0,COLS/2+5);
  box(stats,0,0);
  Screen::createScreen(stats);
  refresh();




  //create player
  Player player(city,1,1);
  Simulation simulate(stats);


  std::thread t1(&Game::runCity,this,std::ref(player));
  std::thread t2(&Game::updateSim,this,std::ref(simulate));
  t1.join();
  t2.join();
  

  delwin(city);
  delwin(stats);
}