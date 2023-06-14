
#include <string>

class Building{
  std::string _building;
  int _rev, _cost, _exp;
  int _pop;

  public:
    // Building(const Building&) = default;
    Building();
    Building(std::string building,int revenue,int pop,int cost, int exp);
    ~Building() = default;
    int getrev();
    int getpop();
    int getCost();
    int getExp();
    std::string getType();

};