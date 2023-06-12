#include <iostream>
#include <ncurses.h>





class Simulation{
  public:
    Simulation(WINDOW* sim);
    void update(int mon,int pop);
    void updatePop(int pop);
    void updateMon(int mon);
    void getCost(int cost);


  private:

    WINDOW* _simWin;
    int _pop;
    int _mon;


};