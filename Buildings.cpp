#include <ncurses.h>
#include <iostream>
#include <string>

#include "buildings.h"

Building::Building() {};

// Building::~Building() {};

Building::Building(std::string building,int revenue,int pop,int cost,int exp) {
  _building = building;
  _rev = revenue;
  _pop = pop;
  _cost = cost;
  _exp = exp;
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

int Building::getExp() {
  return _exp;
}

std::string Building::getType() {
  return _building;
}