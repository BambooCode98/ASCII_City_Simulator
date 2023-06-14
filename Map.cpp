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
  init_color(75,70,800,70);
  init_pair(77,75,COLOR_GREEN);

  std::vector<std::vector<int>> mapData(_sy,std::vector<int>(_sx)); 

  

  mvprintw(50,190,"%d",mapData.size());
  for(int i = 0; i < _sy; i++) {
    for(int j = 0; j < _sx; j++) {
      mapData[i][j] = ' ';
      if(i/2 == 5 || j/3 == 5) {
        mapData[i][j] = '~';
      } else if(i>25 && j>25 && i<_sy && j<_sx) {
        mapData[i][j] = 'T';
      }

      if(mapData[i][j] == ' ') {
        wattron(_win,COLOR_PAIR(10));
        wprintw(_win,"%c", mapData[i][j]);
        wattroff(_win,COLOR_PAIR(10));
      } else if (mapData[i][j] == '~') {
        wattron(_win,COLOR_PAIR(4));
        wprintw(_win,"%c", mapData[i][j]);
        wattroff(_win,COLOR_PAIR(4));
      } else if (mapData[i][j] == 'T') {
        wattron(_win,COLOR_PAIR(77));
        wprintw(_win,"%c", mapData[i][j]);
        wattroff(_win,COLOR_PAIR(77));
      }
      
      if(j == 5) {
        mapData[i][j] = '~';
        // wattron(_win,COLOR_PAIR(4));
        // wprintw(_win,"%c",mapData[i][j]);
        // wattroff(_win,COLOR_PAIR(4));
      }
      // wrefresh(_win);
    }
    wprintw(_win,"\n");
  }
}