#ifndef DISPLAY16_H
#define DISPLAY16_H

#include "gl_canvas2d.h"
#include<windows.h>
#include <chrono>
#include <ctime>
#include <iostream>

class Display16{


public:
    Display16();

    void setGap(int value);
    void setTam(int value);
    void setSide(int value);
    void setPosX(int value);
    void setPosY(int value);

    void drawF(int r, int g, int b);
    void drawD1(int r, int g, int b);
    void drawE(int r, int g, int b);
    void drawM(int r, int g, int b);
    void drawB(int r, int g, int b);
    void drawI(int r, int g, int b);
    void drawA2(int r, int g, int b);
    void drawA1(int r, int g, int b);
    void drawG2(int r, int g, int b);
    void drawG1(int r, int g, int b);
    void drawC(int r, int g, int b);
    void drawL(int r, int g, int b);
    void drawD2(int r, int g, int b);
    void drawJ(int r, int g, int b);
    void drawK(int r, int g, int b);
    void drawH(int r, int g, int b);

    void DrawDigit(int idx);

    void DrawClock(int number);

    void Anima(int number);

private:
    int gap,halfGap,side,posX,posY;
    int tam = 5;
    float x_h[6] = {0,tam,tam*5,tam*6, tam*5, tam};
    float y_h[6] = {0,tam,tam,0,-tam,-tam};

    float x_v[6] = {0,-tam,-tam,0,tam,tam};
    float y_v[6] = {0,tam,tam*5,tam*6,tam*5,tam};

    float x_dr[6] = {tam,tam*2.5,tam*5,tam*5,tam*3.5,tam};
    float y_dr[6] = {-tam,-tam,-tam*3.5,-tam*5,-tam*5,-tam*2.5};

    float x_dl[6] = {tam*3.5,tam*5,tam*5,tam*2.5,tam,tam};
    float y_dl[6] = {-tam,-tam,-tam*2.5,-tam*5,-tam*5,-tam*3.5};

    const int BinaryTable[36] = {
        0b1111111100100100,
        0b0011000000100000,
        0b1110111000011000,
        0b1111110000001000,
        0b0011000100011000,
        0b1101110100011000,
        0b1001111100011000,
        0b1111000000000000,
        0b1111111100011000,
        0b1111100100011000,
        0b1111001100011000,
        0b1111110001001010,
        0b1100111100000000,
        0b1111110001000010,
        0b1100111100010000,
        0b1100001100010000,
        0b1101111100001000,
        0b0011001100011000,
        0b1100110001000010,
        0b0011111000000000,
        0b0000001100110001,
        0b0000111100000000,
        0b0011001110100000,
        0b0011001110000001,
        0b1111111100000000,
        0b1110001100011000,
        0b1111111100000001,
        0b1110001100011001,
        0b1101110100011000,
        0b1100000001000010,
        0b0011111100000000,
        0b0000001100100100,
        0b0011001100000101,
        0b0000000010100101,
        0b0011110100011000,
        0b1100110000100100
    };

    float cellSize, halfCellSize;
};

#endif // DISPLAY16_H
