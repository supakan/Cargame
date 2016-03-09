#ifndef REDRAW2_H_
#define REDRAW2_H_
#define MAX_COUNT 100
typedef struct position{
  int x;
  int y;
}POSITION;

//int encounter(POSITION *player, POSITION *monster);
void initPlayerLocation(POSITION *player);
void getPlayerLocation(POSITION *player, int ch);
#endif /* REDRAW2_H_ */
