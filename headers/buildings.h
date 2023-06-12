
#include <string>

class Building{
  std::string _building;
  int _rev, _cost;
  int _pop;

  public:
    // Building(const Building&);
    Building();
    Building(std::string building,int revenue,int pop,int cost);
    int getrev();
    int getpop();
    int getCost();
    std::string getType();

};