#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>


#include "game.h"
// #include "screen.h"
// #include "player.h"
#include "simulation.h"


Simulation::Simulation(WINDOW* sim) {
  _simWin = sim;
}

auto now() {
  return std::chrono::steady_clock::now();
}

auto awake() {
  using std::chrono::operator""ms;
  return now() + 2000ms;
}


void Simulation::updatePop(int pop) {
  _pop = pop;
  // std::this_thread::sleep_until(awake());

}

void Simulation::updateMon(int mon) {
  _mon = mon;
  std::this_thread::sleep_until(awake());

}

void Simulation::update(int mon,int pop) {

  //update
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