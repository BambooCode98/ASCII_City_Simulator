#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>


#include "game.h"
// #include "screen.h"
// #include "player.h"
#include "simulation.h"
#include "buildings.h"


Simulation::Simulation(WINDOW* sim, Building &r, Building &c, Building &i) {
  _simWin = sim;
  _res = &r;
  _com = &c;
  _ind = &i;
}

auto now() {
  return std::chrono::steady_clock::now();
}

auto awake() {
  using std::chrono::operator""ms;
  return now() + 2000ms;
}


void Simulation::updatePop(int pop) {
  _rPop = _res->getpop();
  _pop = (_rPop*_numr);
  // std::this_thread::sleep_until(awake());

}

void Simulation::updateMon(int mon) {
  if(_numr != 0) {
    _rmonR = _res->getrev();
  }
  if (_numc != 0) {
    _cmonR = _com->getrev();
  }
  if (_numi != 0) {
    _imonR = _ind->getrev();
  }
  // _exp = _rmonC;
  _inc =(_rmonR*_numr)+(_cmonR*_numc)+(_imonR*_numi)-_exp;
  // _mon =- _rmonC;
  // mvprintw(LINES/2, COLS/1.5, "Name: %s", name.c_str());
  _mon += (_inc);
  std::this_thread::sleep_until(awake());

}

void Simulation::update(int mon,int pop, int numr, int numc, int numi) {


  _numr = numr;
  _numc = numc;
  _numi = numi;

  // update
  // updatePop();
  // updateMon();
  std::thread popt(&Simulation::updatePop,this,pop);
  std::thread mont(&Simulation::updateMon,this,mon);
  popt.join();
  mont.join();
  


  //display
  mvwprintw(_simWin, 1, 1, "Population: %d       ", _pop);
  mvwprintw(_simWin, 3, 1, "Money: %d            ", _mon);
  mvwprintw(_simWin, 5, 1, "Date: ");
  // mvwprintw(_simWin, "SIM");
  wrefresh(_simWin);
  // refresh();

}


void Simulation::getCost(int cost) {
  _mon -= cost;
}

void Simulation::subMon(char b) {
  if(b == 'r') {
    _mon -= _res->getCost();
  } else if( b == 'c') {
    _mon -= _com->getCost();
  } else if( b == 'i') {
    _mon -= _ind->getCost();
  }
}