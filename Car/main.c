// -*- coding: utf-8 -*-

#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tictactoe.h"
#include "redraw2.h"

#define DELAY 300
#define MAX_ENEMY 10
#define TOTAL 10000
#define column 28
#define ROW 16

int jump=2;

void getPlayerLocation(POSITION *player, int key) {

	mvprintw(25,20,"             ");
	mvprintw(26,20,"                  ");
	mvprintw(27,20,"                    ");
	mvprintw(28,20,"                      ");
	mvprintw(29,20,"                   ");
	mvprintw(30,20,"                   ");
	mvprintw(31,20,"                   ");
	mvprintw(32,20,"                 ");
	mvprintw(33,20,"                                            ");
	mvprintw(34,20,"                                            ");
	mvprintw(35,20,"                                            ");
	mvprintw(36,20,"                                           ");
	mvprintw(37,20,"                                            ");
	mvprintw(38,20,"                                            ");
	mvprintw(39,20,"                                            ");
	mvprintw(40,20,"                                            ");
	mvprintw(41,20,"                                            ");
	mvprintw(42,20,"                                            ");
	mvprintw(43,20,"                                            ");	
	mvprintw(22,20,"Time : 00");

  switch(key) {
  case KEY_LEFT:
    if(player->x > 16)
      player->x-=3;
    break;
  case KEY_RIGHT:
    if(player->x < (column)) 
      player->x+=3;
    break;
  case KEY_UP:
    if(player->y > 2)
      player->y-=3;
    break;
  case KEY_DOWN:
    if(player->y < ROW-2)
      player->y+=3;
    break;
  case ' ':
    if(player->y > 5 && jump > 0){
      player->y-=6;
	jump--;
	}
    break;
	
  default:
    break;
  }
}

void createBeer(int z){
			mvprintw(25,20,"       {  ::}");
			mvprintw(26,20,"       |   =| ^ ^");
			mvprintw(27,20,"       |  :=|=^o^=)");
			mvprintw(28,20,"       |  :=|  c))");	
			mvprintw(29,20,"       i  :=C,,).~");
			mvprintw(30,20,"       i  ::i.");
			mvprintw(31,20,"     ./,'  ::',");
			mvprintw(32,20,"     /.;   .::'");
			mvprintw(33,20,"   ./ ;     .::',          , -'~'-^~,");
			mvprintw(34,20,"  ./       ..:;'|         (^  u ~'  o)");
			mvprintw(35,20,"   |::_________=|        (u ι °  °  ~ )");
			mvprintw(36,20,"   |r__________-|       ( (,',-, -,ι,_`) o");			
			mvprintw(37,20,"   |:: ____   ::|      o |:o u ° .  °  L__°");
			mvprintw(38,20,"   |:  (beer)  :|     °  |: °  °    °  _  |");
			mvprintw(39,20,"   |:        :::|        |:i::i:i::i: ! | |");
			mvprintw(40,20,"   |:          :|        |:i;i:;i:i:; |_/ /");
			mvprintw(41,20,"   |____________|        |::;::i:::::  __/");
			mvprintw(42,20,"   |______      |        | i___i__i_i |");
			mvprintw(43,20,"   L____________|        L___________|");
			mvprintw(22,20,"Time : %.2d", z);
}

getPlayerDrunkenLocation(POSITION *player, int key,int a){
int n;
init_pair(10,COLOR_YELLOW,COLOR_BLACK);
init_pair(11,COLOR_WHITE,COLOR_BLACK);
init_pair(20,COLOR_WHITE,COLOR_BLACK);
n=rand()%2;
    n=n+10;
attrset(COLOR_PAIR(n));
createBeer(a);
attrset(COLOR_PAIR(20));


  

 switch(key) {
  case KEY_LEFT:
	 if(player->x < (column)) 
      player->x+=3;
    
    break;
  case KEY_RIGHT:
   if(player->x > 16)
      player->x-=3;
    break;
  case KEY_UP:
   if(player->y < ROW-2)
      player->y+=3;
    break;
  case KEY_DOWN:
	 if(player->y > 2)
      player->y-=3;
    break;
  case ' ':
    if(player->y > 5 && jump > 0){
      player->y-=6;
	jump--;
	}
    break;	
  default:
    break;
  }

}

void over(){
		mvprintw(20,20,"Game Over");
		refresh();
}







int main(int argc, char** argv) {
		POSITION *player=(POSITION *)malloc(sizeof(POSITION));
		POSITION *enemy=(POSITION *)malloc(sizeof(POSITION)*MAX_ENEMY);
		POSITION *t=(POSITION *)malloc(sizeof(POSITION)*MAX_ENEMY);
		POSITION *d=(POSITION *)malloc(sizeof(POSITION)*MAX_ENEMY);
		POSITION *r=(POSITION *)malloc(sizeof(POSITION)*MAX_ENEMY);
		POSITION *jump1=(POSITION *)malloc(sizeof(POSITION)*MAX_ENEMY);
		int i=0;
		int level=1;
		int lose = 0 ;
		int ch;
		int num=0;
		int count=0;
		int car=2;
		int score=0;
		int score1=0;
		int score2=0;
		int a=0;
		int count1=0;
		int count2=0;
		int count3=0;
		int count4=0;
		int tr=0;
		int max;
		int drunk=0;
		int j=0;
		int k=0;
		int x;
		int row;
		int arrays[2];
		initscr();
		cbreak();
		noecho();
		curs_set(0);
		timeout(0);
		keypad(stdscr, TRUE);
		while(ch != ' '){
			start_color();
			startgame();
			ch=getch();
		}
		clear();
	
		player->x=16;
  		player->y=15;	
		refresh();
		for(i=0;i<10;i++){
		enemy[i].y =-2;
		}

		for(i=0;i<10;i++){
		t[i].y =-2;
		}

		for(i=0;i<10;i++){
		d[i].y =-2;
		}

		for(i=0;i<10;i++){
		r[i].y =-2;
		}
		
		for(i=0;i<10;i++){
		jump1[i].y =-2;
		}
		
		while (ch != 'q') {
		if(lose == 0 ){
		  if(count%2000 ==0)
		  	drawBoard();

		  if(count%500 == 0 && count != 0){
			  count2++;
			  if(count2%5 == 0 && count2%10 != 0) {
					for (i = 0; i < TOTAL; i++)	
					car =rand()%5;		
					for(i=0;i<10;i++){
					if(enemy[i].y == -2 && count1 < car){
					setPositionEnemycar(enemy,i,car,num);
					count1++;
					num++;
					}

					else if(count1 == car){
					count1 = 0 ;
					num=0;
					break;
				}
					}
					}

			  else if(count2%10 == 0 && count2%2 == 0){
				for(j=0;j<2;j++){

					if(count4 == 0){
					k=0;
						while(k<2){
					row=rand()%5;
        				for (x =  0; x < k; x++){
            				
						if(arrays[x]==row){
                				break;
            					}
        				}
        				if(x == k){
           	 				arrays[k]=row;
						k++;
        					}
    					  }
					}

					for (i = 0; i < TOTAL; i++)		
					tr =rand()%20;
                                        //tr=3;
					if(tr == 1 || tr == 2 ){
						for(i=0;i<10;i++){
							if(t[i].y == -2 && count1 == 0){
								setPositionT(t,i,arrays,count4);
								count1++; }
				 			else if(count1 == 1){
								count1 =0;
								break;}
							}
						}
					else if(tr == 3 || tr == 4 || tr == 10){
						for(i=0;i<10;i++){
							if(d[i].y == -2 && count1 == 0){
								setPositionD(d,i,arrays,count4);
								count1++; }
				 			else if(count1 == 1){
								count1 =0;
								break;}
							}
						}
					else if(tr == 5 || tr == 6 || tr == 11 || tr == 12){
						for(i=0;i<10;i++){
							if(r[i].y == -2 && count1 == 0){
								setPositionTrap(r,i,arrays,count4);
								count1++; }
				 			else if(count1 == 1){
								count1 =0;
								break;}
							}
						}
					else if(tr == 7){
						for(i=0;i<10;i++){
							if(jump1[i].y == -2 && count1 == 0){
								setPositionJump(jump1,i,arrays,count4);
								count1++; }
				 			else if(count1 == 1){
								count1 =0;
								break;}
							}
						}

						count4++;
					  }
					}
					count4 = 0;
					for(i=0; i<10; i++) {
					if(enemy[i].x != 0){				
					mvprintw(enemy[i].y,enemy[i].x,"   ");
    					getEnemyLocation(enemy,i);
					if(enemy[i].y < 17){  
						init_pair(50,COLOR_RED,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(50));
						mvprintw(enemy[i].y,enemy[i].x," O ");
						mvprintw(enemy[i].y+1,enemy[i].x,"/_\\");
    						mvprintw(enemy[i].y+2,enemy[i].x,"\\O/");
						init_pair(52,COLOR_WHITE,COLOR_BLACK);
						attrset(COLOR_PAIR(52));
						}
			 		else{
						mvprintw(enemy[i].y,enemy[i].x,"   ");
						mvprintw(enemy[i].y+1,enemy[i].x,"   ");
						mvprintw(enemy[i].y+2,enemy[i].x,"   ");
						enemy[i].y=-2;
						enemy[i].x=0;
						
						}
						}
					}

					for(i=0; i<10; i++) {
						if(t[i].x != 0){				
							mvprintw(t[i].y,t[i].x,"   ");
    							gettrLocation(t,i);
							if(t[i].y < 17){
								init_pair(65,COLOR_CYAN,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(65));
								mvprintw(t[i].y,t[i].x," _ ");
								mvprintw(t[i].y+1,t[i].x,"|!|");
    								mvprintw(t[i].y+2,t[i].x,"|_|");
								init_pair(66,COLOR_WHITE,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(66));								
								}
			 				else{
								mvprintw(t[i].y,t[i].x,"   ");
								mvprintw(t[i].y+1,t[i].x,"   ");
								mvprintw(t[i].y+2,t[i].x,"   ");
								t[i].y=-2;
								t[i].x=0;
						
							}
						}
					}

					for(i=0; i<10; i++) {
						if(d[i].x != 0){				
							mvprintw(d[i].y,d[i].x,"   ");
    							getDLocation(d,i);
							if(d[i].y < 17){
								init_pair(63,COLOR_YELLOW,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(63));
								mvprintw(d[i].y,d[i].x,"|b|");
								mvprintw(d[i].y+1,d[i].x,"|e|");
    								mvprintw(d[i].y+2,d[i].x,"|r|");
								init_pair(64,COLOR_WHITE,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(64));
								}
			 				else{
								mvprintw(d[i].y,d[i].x,"   ");
								mvprintw(d[i].y+1,d[i].x,"   ");
								mvprintw(d[i].y+2,d[i].x,"   ");
								d[i].y=-2;
								d[i].x=0;
						
							}
						}
					}
					
					for(i=0; i<10; i++) {
						if(r[i].x != 0){				
							mvprintw(r[i].y,r[i].x,"   ");
    							gettrapLocation(r,i);
							if(r[i].y < 17){
							init_pair(55,COLOR_WHITE,COLOR_BLACK);
							attrset(COLOR_PAIR(55));
								mvprintw(r[i].y,r[i].x,"   ");
								mvprintw(r[i].y+1,r[i].x,"O~*");
    								mvprintw(r[i].y+2,r[i].x,"   ");
							
								}
			 				else{
								mvprintw(r[i].y,r[i].x,"   ");
								mvprintw(r[i].y+1,r[i].x,"   ");
								mvprintw(r[i].y+2,r[i].x,"   ");
								r[i].y=-2;
								r[i].x=0;
						
							}
						}
					}
					
					for(i=0; i<10; i++) {
						if(jump1[i].x != 0){				
							mvprintw(jump1[i].y,jump1[i].x,"   ");
    							getJumpLocation(jump1,i);
							if(jump1[i].y < 17){
							init_pair(61,COLOR_GREEN,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(61));
								mvprintw(jump1[i].y,jump1[i].x,"/\\ ");
								mvprintw(jump1[i].y+1,jump1[i].x,"/\\ ");
    								mvprintw(jump1[i].y+2,jump1[i].x,"/\\ ");
								init_pair(62,COLOR_WHITE,COLOR_BLACK);
	                 			       	attrset(COLOR_PAIR(62));								
								}
			 				else{
								mvprintw(jump1[i].y,jump1[i].x,"   ");
								mvprintw(jump1[i].y+1,jump1[i].x,"   ");
								mvprintw(jump1[i].y+2,jump1[i].x,"   ");
								jump1[i].y=-2;
								jump1[i].x=0;
						
							}
						}
					}

				 	if(drunk > 0){
						drunk--;
					} 
				}
			ch=getch();	
			mvprintw(player->y,player->x,"   ");
			mvprintw(player->y+1,player->x,"   ");
			mvprintw(player->y+2,player->x,"   ");
			if(drunk > 0)
			getPlayerDrunkenLocation(player, ch,drunk);
			else
    			getPlayerLocation(player, ch);

			init_pair(25,COLOR_BLUE,COLOR_BLACK);
			attrset(COLOR_PAIR(25));
    			mvprintw(player->y,player->x,"o o");
			mvprintw(player->y+1,player->x,"|x|");
			mvprintw(player->y+2,player->x,"o o");
			init_pair(28,COLOR_WHITE,COLOR_BLACK);
			attrset(COLOR_PAIR(28));
			lose = checkcrash(enemy,player,lose);
			score1 = gett(t,player,score1);
			score1 = gettrap(r,player,score1);
			drunk = getD(d,player,drunk);
			jump = getj(jump1,player,jump);
			mvprintw(21,2,"Level %d",level);
			mvprintw(22,2,"Jump %d",jump);
		
			
			score = count/1000;
			level = ((count/1000)/50)+1;
			score2 = 10*score1;
			score =score + score2;
		
			mvprintw(20,2,"Scores = %d   ",score);
			
				
			usleep(DELAY/level);
			count++;
			refresh();
			}
			else{
			usleep(700000);
					
					
					if(count3 == 0 ){
						clear();
						gameover();
						loadHighScore();
						saveHighScore(score);
						highScoreDisp();
						init_pair(64,COLOR_CYAN,COLOR_BLACK);
						attrset(COLOR_PAIR(64));
						mvprintw(29, 52, "Your score is %d",score);
						count3=1;
					}
					ch=getch();
					if(ch == ' '){
						level=1;
						lose = 0 ;
						count3=0;
						num=0;
						count=0;
						score=0;
						score1=0;
						score2=0;
						count1=0;
						count2=0;
						drunk=0;
						j=0;
						k=0;
						jump=2;
						clear();
						drawBoard();
						player->x=16;
  						player->y=15;	
						refresh();
						for(i=0;i<10;i++){
							enemy[i].y =-2;
							enemy[i].x = 0;
						}

						for(i=0;i<10;i++){
							t[i].y =-2;
							t[i].x = 0;
						}

						for(i=0;i<10;i++){
							r[i].y =-2;
							r[i].x = 0;
						}
						
						for(i=0;i<10;i++){
							d[i].y =-2;
							d[i].x = 0;
						}
						
						for(i=0;i<10;i++){
						jump1[i].y =-2;
						jump1[i].x = 0;
						}
					}
				
			}
		}
	
		   	 

	endwin();
	return(0);
}
