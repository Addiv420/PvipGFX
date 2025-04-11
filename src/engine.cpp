#include "engine.h"
#include "vipgfx.h"
#include <unistd.h>

int pointsR;
int pointsL;
int board1y;
int board2y;
int boardSize;

int ballX, ballY;
int ballDirectionX, ballDirectionY;
int ballRadius;

void init() {
    pointsR = 0;
    pointsL = 0;
    ballX = 300;
    ballY = 300;
    boardSize = 64;
    board1y = 200;
    board2y = 500;
    ballRadius = 8;
    ballDirectionX = +1;
    ballDirectionY = +1;
}

void moveBoard1() {
    if (keyboard[KEY_W]) {
        board1y--;
        if (board1y < 0) board1y = 0;
    }
    if (keyboard[KEY_S]) {
        board1y++;
        if ((board1y + boardSize) > (vscreen.height - 1))
            board1y = vscreen.height - boardSize - 1;
    }
}

void moveBoard2() {
    if (keyboard[KEY_UP]) {
        board2y--;
        if (board2y < 0) board2y = 0;
    }
    if (keyboard[KEY_DOWN]) {
        board2y++;
        if ((board2y + boardSize) > (vscreen.height - 1))
            board2y = vscreen.height - boardSize - 1;
    }
}

void ballBounce() {
    if (ballY + ballRadius <= 0) ballDirectionY = +1;
    if (ballY + ballRadius >= vscreen.height) ballDirectionY = -1;
}

void score() {
    if (ballX == 0) {
        pointsR = +1;
    }
    else if (ballX == vscreen.width) {
        pointsL = +1;
    }
}

void update() {
    moveBoard1();
    moveBoard2();
    ballBounce();
    moveBall();
    score();

    if (hitBoard1()) ballDirectionX = +1;
    if (hitBoard2()) ballDirectionX = -1;
}

void moveBall() {
    ballX += ballDirectionX;
    ballY += ballDirectionY;
}

bool hitBoard1() {
    return (ballY > board1y) && (ballY < (board1y + boardSize)) && (ballX - ballRadius < 10);
}

bool hitBoard2() {
    return (ballY > board2y) && (ballY < (board2y + boardSize)) && (ballX + ballRadius > vscreen.width - 10);
}

void draw() {
    DrawBarClip(vscreen, 4, board1y, 10, board1y + boardSize, 0xff000000);
    DrawBarClip(vscreen, vscreen.width - 10, board2y, vscreen.width - 4, board2y + boardSize, 0xff000000);
    DrawFilledCircleClip(vscreen, ballX, ballY, ballRadius, 0xff000000);
    DrawFilledCircleClip(vscreen, vscreen.width / 3, vscreen.height / 3, ballRadius, colors[pointsR]);
    usleep(5000);
}

void finish() {
}
