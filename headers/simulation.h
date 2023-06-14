#include <iostream>
#include <ncurses.h>


class Building;


class Simulation{
  public:
    Simulation(WINDOW* sim, Building &r, Building &c, Building &i);
    void update(int mon,int pop, int numr, int numc, int numi);
    void updatePop(int pop);
    void updateMon(int mon);
    void getCost(int cost);
    void subMon(char b);
    void getOtherBuildings(Building &road);
    void getNumExtraBuild(int nRoads);


  private:

    WINDOW* _simWin;
    //base stats
    int _pop = 0;
    int _mon = 5000;
    Building* _res;
    Building* _com;
    Building* _ind;
    Building* _road;
    //expenses
    int _exp = 0;
    int _roadE = 0;
    //income
    int _inc = 0;
    //number of buildings
    int _numr, _numc, _numi;
    int _numRoads;
    //cost and revenue of buildings
    int _rmonR, _rmonC, _cmonR, _cmonC, _imonR, _imonC;
    //pop from residential
    int _rPop;


};