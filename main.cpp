#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ncurses.h>


using namespace std;





int main() {

  initscr();

  cbreak();
  noecho();
  clear();
  curs_set(0);



  endwin();

  return 0;

} 
