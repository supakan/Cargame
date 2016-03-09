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
#include "redraw2.h"

void getJumpLocation(POSITION *t, int j) {
  t[j].y++;
}


void setPositionJump(POSITION *t, int j,int* array,int count){
	int row=0;
	int p;
	int i;
	int x;

		//row = rand()%5;
	    	row=array[count];
		if(row==0){
			t[j].x=16;
			t[j].y=-2;
			mvprintw(t[j].y,t[j].x,"   ");
			getEnemyLocation(t, j);
		}else if(row==1){
			t[j].x=19;
			t[j].y=-2;
			mvprintw(t[j].y,t[j].x,"   ");
			getEnemyLocation(t, j);
		}else if(row==2){
			t[j].x=22;
			t[j].y=-2;
			mvprintw(t[j].y,t[j].x,"   ");
			getEnemyLocation(t, j);
		}else if(row==3){
			t[j].x=25;
			t[j].y=-2;
			mvprintw(t[j].y,t[j].x,"   ");
			getEnemyLocation(t, j);
		}else{
			t[j].x=28;
			t[j].y=-2;
			mvprintw(t[j].y,t[j].x,"   ");
			getEnemyLocation(t, j);
			}
}

int getj(POSITION *enemy,POSITION *player,int score){
	int i;
	for(i=0;i<10;i++){
		if(enemy[i].x != 0){	
			if(enemy[i].y == player->y+1 && enemy[i].x == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
    			score++;
				break;
    			}//6->1
    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;	
				score++;
				break;
    			}//7->1

    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x+1){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//8->1

    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;	
				score++;
				break;
    			}//9->1

    			else if(enemy[i].y == player->y+1 && enemy[i].x+2 == player->x){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//4->3

    			else if(enemy[i].y == player->y+2 && enemy[i].x+2 == player->x){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//7->3

    			else if(enemy[i].y == player->y+2 && enemy[i].x+2 == player->x+1){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;	
				score++;
				break;
    			}//8->3

    			else if(enemy[i].y+2 == player->y && enemy[i].x == player->x+1){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;	
				score++;
				break;
    			}//2->7

    			else if(enemy[i].y+2 == player->y && enemy[i].x == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;	
				score++;
				break;
    			}//3->7

    			else if(enemy[i].y+2 == player->y+1 && enemy[i].x == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//6->7

    			else if(enemy[i].y+2 == player->y+2 && enemy[i].x == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//9->7

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x+1){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//2->9

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x){
   				mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//1->9

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//3->9

    			else if(enemy[i].y+2 == player->y+1 && enemy[i].x+2 == player->x+2){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
			    score++;
				break;
    			}//4->9

    			else if(enemy[i].y+2 == player->y+2 && enemy[i].x+2 == player->x){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//2->9

    			else if(enemy[i].y+1 == player->y+2 && enemy[i].x == player->x){
    			mvprintw(enemy[i].y,enemy[i].x,"   ");
				mvprintw(enemy[i].y+1,enemy[i].x,"   ");
				mvprintw(enemy[i].y+2,enemy[i].x,"   ");
				enemy[i].y=-2;
				enemy[i].x=0;
				score++;
				break;
    			}//7->4
    		}
    	}
	return score;
}		


