/* Copyright (C) 2013-2016 Angus Galloway
 * angus.galloway.ca@ieee.org
 * 
 * This file is part of tictactoe-ncurses
 *
 * tictactoe-ncurses is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tictactoe-ncurses is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "tictactoe.h"
#include "redraw2.h"

#define column 28
#define ROW 16

void gameover(){
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	int i;
	for(i=1;i<=32;i++){
		if(i==1||i==32){
			int j;
			for(j=1;j<=115;j++){
				attrset(COLOR_PAIR(4));		
				mvprintw(i,j,"#");
				}
		}
		else{
			attrset(COLOR_PAIR(4));
			mvprintw(i,1,"#");
			mvprintw(i,115,"#");
		}
	}
	
	attrset(COLOR_PAIR(5));
	mvprintw(4,4,"                  ################   #########          ######       ######   ##################           ");
	mvprintw(5,4,"                 ################   ###########         ##### ##   ## #####    ##################          ");
	mvprintw(6,4,"                ####               #####   #####        #####   ####  #####     ######                     ");
	mvprintw(7,4,"               ####     #######   #####     #####       #####    ##   #####      #################         ");
	mvprintw(8,4,"              ####     #######   #################      #####         #####       #################        ");
	mvprintw(9,4,"             ####        ####   ###################     #####         #####        #######                 ");
	mvprintw(10,4,"            ################   #####           #####    #####         #####         ##################     ");
	mvprintw(11,4,"           ################   #####             #####   #####         #####          ##################    ");
        
	attrset(COLOR_PAIR(5));     
	mvprintw(13,4,"          ################    #######        #######    ################      ################             ");
	mvprintw(14,4,"         ################       ####         ####       ################       #################           ");
	mvprintw(15,4,"        ####        ####         ####       ####        ######                  #####     #######          ");
	mvprintw(16,4,"       ####        ####           ####     ####         ###########              #####  ########           ");
	mvprintw(17,4,"      ####        ####             ####   ####          ###########               #############            ");
	mvprintw(18,4,"     ####        ####               #### ####           ######                     #####     #####         ");
	mvprintw(19,4,"    ################                 #######            ################            #####      ######      ");
	mvprintw(20,4,"   ################                   #####             ################             #####       #######   ");
}



void startgame(){
	start_color();
  	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	int i;
	for(i=1;i<=30;i++){
		if(i==1||i==30){
			int j;
			for(j=1;j<=82;j++){
				attrset(COLOR_PAIR(5));					
				mvprintw(i,j,"#");
				}
		}
		else{
			attrset(COLOR_PAIR(5));
			mvprintw(i,1,"#");
			mvprintw(i,82,"#");
		}
	}
	
	attrset(COLOR_PAIR(2));
	mvprintw(2,3,"                                 ___________________________");
	mvprintw(3,3,"                               //##################//        \\\\");
	mvprintw(4,3,"                             //##################//____        \\\\");
	mvprintw(5,3,"                           //##################// |____|         \\\\");
	attrset(COLOR_PAIR(3));
	mvprintw(6,3,"                       _//__________________//___//________________\\\\");
	mvprintw(7,3,"                    /                    /_________            ___");
	mvprintw(8,3,"              __/_____________________/_________              |===|");
	mvprintw(9,3,"            (/___***_____***______(      _____      ________");
	attrset(COLOR_PAIR(4));
	mvprintw(10,3,"          (/____*****___*****____       /(xxx)\\   _________");
	mvprintw(11,3,"          (/_____***_____***______)    /(xxxxx)\\________");
	mvprintw(12,3,"            (/____|AW-121|___________/)\\(xxxxx)/");

	attrset(COLOR_PAIR(2));
	mvprintw(14,4,"        _ _ _ _ _ _            _ _ _ _ _ _            _ _ _ _ _ _ _");
	mvprintw(15,4,"      /_/_/_/_/_/_/\\         /_/_/_/_/_/_/\\         /_/_/_/_/_/_/_/\\");
	mvprintw(16,4,"     /_/_/_/_/_/_/\\/        /_/\\_\\_\\_\\/_/\\/        /_/\\_\\_\\_\\_\\/_/\\/");
	mvprintw(17,4,"    /_/_/\\/\\_\\_\\/\\/        /_/\\/_ _ _/_/\\/        /_/\\/_ _ _ _/_/\\/");
	mvprintw(18,4,"   /_/_/\\/                /_/_/_/_/_/_/\\/        /_/_/_/_/_/_/_/\\/");
	mvprintw(19,4,"  /_/_/\\/_ _ _           /_/\\/\\_\\_\\/_/\\/        /_/\\/\\_\\_\\_\\_\\_\\/");
	mvprintw(20,4," /_/_/_/_/_/_/\\         /_/\\/     /_/\\/        /_/\\/     /_/\\/");
	mvprintw(21,4,"/_/_/_/_/_/_/\\/        /_/\\/     /_/\\/        /_/\\/     /_/\\/");
	mvprintw(22,4,"\\_\\_\\_\\_\\_\\_\\/         \\_\\/      \\_\\/         \\_\\/      \\_\\/");

	attrset(COLOR_PAIR(1));
	mvprintw(28,30,"Press spacebar to start");

	
}

void drawBoard() {

  int i, h;
  initscr();
  start_color();
  init_pair(1,COLOR_RED,COLOR_GREEN);
  int a = rand()%2;
  if(a == 1){
  init_pair(2,COLOR_YELLOW,COLOR_BLACK);
}
  else if (a == 0){
  init_pair(2,COLOR_GREEN,COLOR_BLACK);
}
  init_pair(3,COLOR_WHITE,COLOR_BLACK);
  for(i=0;i<=17;i++) {
    attrset(COLOR_PAIR(1));
    mvaddch(i, 15, '|');
    mvaddch(i,31,'|');
  }
   attrset(COLOR_PAIR(2));
   mvaddstr(0,0,"    (;;);;)");
   mvaddstr(1,0,"  (;;);;;);;)");
   mvaddstr(2,0,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(3,0,"      |i!|");
  mvaddstr(4,0,"      |ii|");
  attrset(COLOR_PAIR(2));
  mvaddstr(6,0,"    (;;);;)");
  mvaddstr(7,0,"  (;;);;;);;)");
  mvaddstr(8,0,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(9,0,"      |i!|");
  mvaddstr(10,0,"      |ii|");
  attrset(COLOR_PAIR(2));
  mvaddstr(12,0,"    (;;);;)");
  mvaddstr(13,0,"  (;;);;;);;)");
  mvaddstr(14,0,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(15,0,"      |i!|");
  mvaddstr(16,0,"      |ii|");	


  attrset(COLOR_PAIR(2));
  mvaddstr(0,32,"    (;;);;)");
  mvaddstr(1,32,"  (;;);;;);;)");
  mvaddstr(2,32,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(3,32,"      |i!|");
  mvaddstr(4,32,"      |ii|");
  attrset(COLOR_PAIR(2));
  mvaddstr(6,32,"    (;;);;)");
  mvaddstr(7,32,"  (;;);;;);;)");
  mvaddstr(8,32,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(9,32,"      |i!|");
  mvaddstr(10,32,"      |ii|");
  attrset(COLOR_PAIR(2));
  mvaddstr(12,32,"    (;;);;)");
  mvaddstr(13,32,"  (;;);;;);;)");
  mvaddstr(14,32,"    (;;(;;;)");
  attrset(COLOR_PAIR(3));
  mvaddstr(15,32,"      |i!|");
  mvaddstr(16,32,"      |ii|");

  init_pair(40,COLOR_WHITE,COLOR_BLACK);
  init_pair(41,COLOR_YELLOW,COLOR_BLACK);
  init_pair(42,COLOR_RED,COLOR_BLACK);
  init_pair(43,COLOR_GREEN,COLOR_BLACK);
  init_pair(44,COLOR_CYAN,COLOR_BLACK);

  attrset(COLOR_PAIR(44));
  mvprintw(0,55," _ ");
  mvprintw(1,55,"|!|  is treasure (Increase your point).");
  mvprintw(2,55,"|_|");

  attrset(COLOR_PAIR(42)); 
  mvprintw(4,55," O ");
  mvprintw(5,55,"/_\\  is enemy car (If you crash it, game will be over).");
  mvprintw(6,55,"\\O/");

  attrset(COLOR_PAIR(41));
  mvprintw(8,55,"|b|");
  mvprintw(9,55,"|e|  is beer (If you get it, you will be drunken state).");
  mvprintw(10,55,"|r|");

  attrset(COLOR_PAIR(40));
  mvprintw(12,55,"   ");
  mvprintw(13,55,"O~*  is bomb (Decrease your point).");
  mvprintw(14,55,"   ");

  attrset(COLOR_PAIR(43));
  mvprintw(15,55,"/\\ ");
  mvprintw(16,55,"/\\  is Nitrous (Increase jump point).");
  mvprintw(17,55,"/\\ ");

  refresh();
    }
