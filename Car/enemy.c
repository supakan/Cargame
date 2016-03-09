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

#define MAX_ENEMY 10
int array[4];

void getEnemyLocation(POSITION *enemy, int j) {
  enemy[j].y++;
}


int enemyCar(){
	int num=0;
	num = rand()%4;
	mvprintw(19,2,"num = %d",num);

	return num;
}

void setPositionEnemycar(POSITION *enemy, int j,int car,int num){
	int row=0;
	int p;
	int i=0;
	int x;

		if(num == 0){

		while(i<car){
        row=rand()%5;

        for (x =  0; x < i; x++)
        	{
            	if(array[x]==row){
                break;
            	}
        	}
        		if(x == i){
           	 array[i]=row;
		i++;
        	}
    	}
	}
	row=array[num];
		if(row==0){
			enemy[j].x=16;
			enemy[j].y=-2;
			mvprintw(enemy[j].y,enemy[j].x,"   ");
			getEnemyLocation(enemy, j);
		}else if(row==1){
			enemy[j].x=19;
			enemy[j].y=-2;
			mvprintw(enemy[j].y,enemy[j].x,"   ");
			getEnemyLocation(enemy, j);
		}else if(row==2){
			enemy[j].x=22;
			enemy[j].y=-2;
			mvprintw(enemy[j].y,enemy[j].x,"   ");
			getEnemyLocation(enemy, j);
		}else if(row==3){
			enemy[j].x=25;
			enemy[j].y=-2;
			mvprintw(enemy[j].y,enemy[j].x,"   ");
			getEnemyLocation(enemy, j);
		}else{
			enemy[j].x=28;
			enemy[j].y=-2;
			mvprintw(enemy[j].y,enemy[j].x,"   ");
			getEnemyLocation(enemy, j);
			}

}

int checkcrash(POSITION *enemy,POSITION *player,int lose){
	int i;
	for(i=0;i<10;i++){
		if(enemy[i].x != 0){	
			if(enemy[i].y == player->y+1 && enemy[i].x == player->x+2){
    				over();
				lose++;
				break;
    			}//6->1
    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x){
    				over();
				lose++;
				break;
    			}//7->1

    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x+1){
    				over();
				lose++;
				break;
    			}//8->1

    			else if(enemy[i].y == player->y+2 && enemy[i].x == player->x+2){
    				over();
				lose++;
				break;
    			}//9->1

    			else if(enemy[i].y == player->y+1 && enemy[i].x+2 == player->x){
    				over();
				lose++;
				break;
    			}//4->3

    			else if(enemy[i].y == player->y+2 && enemy[i].x+2 == player->x){
    				over();
				lose++;
				break;
    			}//7->3

    			else if(enemy[i].y == player->y+2 && enemy[i].x+2 == player->x+1){
    				over();
				lose++;
				break;
    			}//8->3

    			else if(enemy[i].y+2 == player->y && enemy[i].x == player->x+1){
    				over();
				lose++;
				break;
    			}//2->7

    			else if(enemy[i].y+2 == player->y && enemy[i].x == player->x+2){
    				over();
				lose++;
				break;
    			}//3->7

    			else if(enemy[i].y+2 == player->y+1 && enemy[i].x == player->x+2){
    				over();
				lose++;
				break;
    			}//6->7

    			else if(enemy[i].y+2 == player->y+2 && enemy[i].x == player->x+2){
    				over();
				lose++;
				break;
    			}//9->7

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x+1){
    				over();
				lose++;
				break;
    			}//2->9

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x){
    				over();
				lose++;
				break;
    			}//1->9

    			else if(enemy[i].y+2 == player->y && enemy[i].x+2 == player->x+2){
    				over();
				lose++;
				break;
    			}//3->9

    			else if(enemy[i].y+2 == player->y+1 && enemy[i].x+2 == player->x+2){
    				over();
				lose++;
				break;
    			}//4->9

    			else if(enemy[i].y+2 == player->y+2 && enemy[i].x+2 == player->x){
    				over();
				lose++;
				break;
    			}//2->9

    			else if(enemy[i].y+1 == player->y+2 && enemy[i].x == player->x){
    				over();
				lose++;
				break;
    			}//7->4
    		}
    	}
	return lose;
}			


