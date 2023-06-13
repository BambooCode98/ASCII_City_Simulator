
#include <string>

class Building{
  std::string _building;
  int _rev, _cost;
  int _pop;

  public:
    // Building(const Building&) = default;
    Building();
    Building(std::string building,int revenue,int pop,int cost);
    ~Building() = default;
    int getrev();
    int getpop();
    int getCost();
    std::string getType();

};