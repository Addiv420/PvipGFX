#ifndef ENGINE_H
#define ENGINE_H

#define RED 0xffff0000\u
#define GREEN 0xff00ff00\u
#define BLUE 0xff0000ff\u

extern int board1y;
extern int board2y;
extern int boardSize;

extern int ballX, ballY;
extern int ballDirectionX, ballDirectionY;
extern int ballRadius;

void init();
void moveBoard1();
void moveBoard2();
void update();
void moveBall();
bool hitBoard1();
bool hitBoard2();
void draw();
void finish();

#endif ENGINE_H
