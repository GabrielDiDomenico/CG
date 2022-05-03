#ifndef DISPLAY16_H
#define DISPLAY16_H

#include "gl_canvas2d.h"
#include<windows.h>


class Display16{


public:
    /*Display16(int g,int s,int pX,int pY){
        gap = g;
        halfGap = g*0.5;
        side = s;
        posX = pX+g;
        posY = pY+tam*2;
        cellSize = tam*12;
        halfCellSize = cellSize*0.5;
    }*/



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



    void DrawCells(int numCells);

    void Anima();

private:
    int gap,halfGap,side,posX,posY;
    int tam = 20;
    float x_h[6] = {0,tam,tam*5,tam*6, tam*5, tam};
    float y_h[6] = {0,tam,tam,0,-tam,-tam};

    float x_v[6] = {0,-tam,-tam,0,tam,tam};
    float y_v[6] = {0,tam,tam*5,tam*6,tam*5,tam};

    float x_dr[6] = {tam,tam*2.5,tam*5,tam*5,tam*3.5,tam};
    float y_dr[6] = {-tam,-tam,-tam*3.5,-tam*5,-tam*5,-tam*2.5};

    float x_dl[6] = {tam*3.5,tam*5,tam*5,tam*2.5,tam,tam};
    float y_dl[6] = {-tam,-tam,-tam*2.5,-tam*5,-tam*5,-tam*3.5};

    const int BinaryTable[4] = {
        0b1111111100100100,
        0b0011000000100000,
        0b1110111000011000,
        0b1111111111111111
    };

    float cellSize, halfCellSize;
};

#endif // DISPLAY16_H
