#include <iostream>
#include <ncurses.h>





class Simulation{
  public:
    Simulation(WINDOW* sim);
    void update(int mon);
    void updatePop(int pop);
    void updateMon(int mon);


  private:

    WINDOW* _simWin;
    int _pop;
    int _mon;


};