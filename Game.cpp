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

void Game::runCity(Player &player,Simulation &simulate) {
  while(_quit != 'p') {
    // refresh();
    _quit = player.moveCursor();
    // wrefresh(_cityWin);
    player.checkforObjs();
    
    if(_quit == 'r') {
      _numR++;
      _rc = true;
      mvprintw(LINES/2,COLS/2,"Created a residential building.");
    } else if (_quit == 'c') {
      _numC++;
      _cc = true;
      mvprintw(LINES/2,COLS/2,"Created a commercial building.");
    } else if (_quit == 'i') {
      _numI++;
      _ic = true;
      mvprintw(LINES/2,COLS/2,"Created an industrial building.");
    }

    _tBuilds = _numC+_numR+_numI;

    mvprintw(LINES/2+1,COLS/2,"Totals: %d", _tBuilds);
    mvprintw(LINES/2+2,COLS/2,"R: %d ",_numR);
    mvprintw(LINES/2+3,COLS/2,"C: %d ", _numC);
    mvprintw(LINES/2+4,COLS/2,"I: %d ", _numI);

    refresh();
  }
  

}

void Game::updateSim(Simulation &simulate) {
  

  while(_quit != 'p') {
    
    if(_rc) {
      simulate.subMon('r');
      _rc = false;
    } else if(_cc) {
      simulate.subMon('c');
      _cc = false;
    } else if(_ic) {
      simulate.subMon('i');
      _ic = false;
    }
    simulate.update(_price,_p,_numR, _numC, _numI);

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
  Building R("Res",1,25,500);
  Building C("Com",25,0,750);
  Building I("Ind",50,0,1000);
  Simulation simulate(stats,R,C,I);


  std::thread t1(&Game::runCity,this,std::ref(player),std::ref(simulate));
  std::thread t2(&Game::updateSim,this,std::ref(simulate));
  t1.join();
  t2.join();
  

  delwin(city);
  delwin(stats);
}