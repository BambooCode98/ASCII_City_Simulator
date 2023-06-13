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
#include "map.h"


Game::Game() {
}

void Game::setQuit(int quit) {
  _quit = quit;
}

void Game::runCity(Player &player,Simulation &simulate) {
  while(_quit != 'p') {
    // refresh();
    _quit = player.moveCursor();
    _envSafe = player.checkEnv();
    mvprintw(LINES-1,COLS-5,"%b",_envSafe);
    // wrefresh(_cityWin);
    // mvwprintw(_cityWin,LINES-25,50,"%d",COLS);
    
    if(_quit == 'r' && _okToBuild && _envSafe) {
      _numR++;
      _rc = true;
      mvprintw(LINES/2,COLS/2,"Created a residential building. ");
    } else if (_quit == 'c' && _okToBuild && _envSafe) {
      _numC++;
      _cc = true;
      mvprintw(LINES/2,COLS/2,"Created a commercial building. ");
    } else if (_quit == 'i' && _okToBuild) {
      _numI++;
      _ic = true;
      mvprintw(LINES/2,COLS/2,"Created an industrial building.");
    }

    _okToBuild = player.checkforObjs();
    mvprintw(LINES-1,COLS-1,"%b",_okToBuild);

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

  Map newMap(LINES,COLS/2,_cityWin);
  newMap.createMap();
  wborder(city,'#','#','#','#','#','#','#','#');
  wrefresh(_cityWin);


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