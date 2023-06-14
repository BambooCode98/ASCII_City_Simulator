#include <iostream>
#include <ncurses.h>
#include <vector>

#include "map.h"
 

Map::Map(int sy, int sx, WINDOW* win) {
  _sx = sx;
  _sy = sy;
  _win = win;
}

void Map::createMap() {
  init_pair(4,COLOR_WHITE,COLOR_CYAN);
  init_color(10,451,438,172);
  init_pair(10,COLOR_WHITE,10);

  std::vector<std::vector<int>> mapData(_sy,std::vector<int>(_sx)); 

  

  mvprintw(50,190,"%d",mapData.size());
  for(int i = 0; i < _sy; i++) {
    for(int j = 0; j < _sx; j++) {
      mapData[i][j] = ' ';
      wattron(_win,COLOR_PAIR(10));
      wprintw(_win,"%c", mapData[i][j]);
      mvprintw(LINES/2,COLS/2,"i:%d j:%d / sy:%d sx:%d",i,j,_sy,_sx);
      wattroff(_win,COLOR_PAIR(10));
      
      if(j%2 == 0) {
        wattron(_win,COLOR_PAIR(4));
        wprintw(_win,"~");
        wattroff(_win,COLOR_PAIR(4));
      }
      // wrefresh(_win);
    }
  }
}