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

int arraypoint[6];


void loadHighScore() {
  int i=0, hg = 0 ;
  FILE *fp;
  fp = fopen("highscore.txt", "r");
  //if(fp != NULL)
     while(fscanf(fp, "%d",&arraypoint[i++]) != EOF){	
  }

  fclose(fp);
}

void saveHighScore(int score) {
  	
  int i;
  int j;
  int hold;
  int s1,s2,s3,s4,s5;
  arraypoint[5] = score;

	for(j=0;j<6-1;j++){
		for(i=0;i<6-j-1;i++){
			if(arraypoint[i] < arraypoint[i+1]){
				hold = arraypoint[i];
				arraypoint[i] = arraypoint[i+1];
				arraypoint[i+1] = hold;
			}
		}
	}
  s1=arraypoint[0];
  s2=arraypoint[1];	
  s3=arraypoint[2];	
  s4=arraypoint[3];	
  s5=arraypoint[4];
		
  FILE *fp;
  fp = fopen("highscore.txt", "w");
  fprintf(fp, "%d\n%d\n%d\n%d\n%d",s1,s2,s3,s4,s5);
  fclose(fp);

}

void highScoreDisp() {
  int i;
  init_pair(8,COLOR_YELLOW,COLOR_BLACK);
  init_pair(10,COLOR_WHITE,COLOR_BLACK);
  init_pair(9,COLOR_CYAN,COLOR_BLACK);
  init_pair(7,COLOR_BLUE,COLOR_BLACK);

	attrset(COLOR_PAIR(10));
	mvprintw(22, 55, "High Scores");
  for(i=0;i<5;i++){
	attrset(COLOR_PAIR(8));
	mvprintw(23+i, 55, "%d. %d",i+1,arraypoint[i]);
	}
  	
	attrset(COLOR_PAIR(10));
  mvprintw(29, 15, "Press Spacebar to play again");
	attrset(COLOR_PAIR(10));
  mvprintw(29, 80, "Press Q to exit");
}



