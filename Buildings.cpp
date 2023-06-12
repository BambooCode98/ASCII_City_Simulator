#include <ncurses.h>
#include <iostream>
#include <string>

#include "buildings.h"

Building::Building() {};

Building::Building(std::string building,int revenue,int pop,int cost) {
  _building = building;
  _rev = revenue;
  _pop = pop;
  _cost = cost;
}

int Building::getrev() {
  return _rev;
}

int Building::getpop() {
  return _pop;
}

int Building::getCost() {
  return _cost;
}

std::string Building::getType() {
  return _building;
}