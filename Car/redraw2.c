// -*- coding: utf-8 -*-

#include <ncurses.h>
#include "redraw2.h"

void initPlayerLocation(POSITION *player) {
  mvprintw(player->y, player->x, " ");
  player->x = 6;
  player->y = 9;
  mvprintw(player->y, player->x, "@");
}

void getPlayerLocation(POSITION *player, int key) {
  switch(key) {
  case KEY_LEFT:
    if(player->x > 0){
      player->x--;
    }
    break;
  case KEY_RIGHT:
    if(player->x < (COLS-1)) 
      player->x++;
    break;
  case KEY_UP:
    if(player->y > 0)
      player->y--;
    break;
  case KEY_DOWN:
    if(player->y < (LINES-1))
      player->y++;
    break;
  default:
    break;
  }
}



