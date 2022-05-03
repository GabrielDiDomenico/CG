#include "Display16.h"

    Display16::Display16(){
        gap = 1;
        halfGap = gap*0.5;
        side = 100;
        posX = 100+gap;
        posY = 100+20*2;
        cellSize = 20*12;
        halfCellSize = cellSize*0.5;
    }

    void Display16::setGap(int value){ gap = value; halfGap = gap*0.5;}
    void Display16::setTam(int value) { tam = value; cellSize = tam*12; halfCellSize = cellSize*0.5;}
    void Display16::setSide(int value){ side = value; }
    void Display16::setPosX(int value){ posX = value+gap; }
    void Display16::setPosY(int value){ posY = value+tam*2; }

    void Display16::drawF(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX-gap,posY+halfCellSize);
        CV::polygonFill(x_v,y_v,6); //f
    }
    void Display16::drawD1(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX,posY);
        CV::polygonFill(x_h,y_h,6); //d1
    }
    void Display16::drawE(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX-gap,posY);
        CV::polygonFill(x_v,y_v,6); //e
    }
    void Display16::drawM(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap*2,posY+halfCellSize);
        CV::polygonFill(x_dr,y_dr,6); //m
    }
    void Display16::drawB(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+cellSize+gap*3,posY+halfCellSize);
        CV::polygonFill(x_v,y_v,6); //b
    }
    void Display16::drawI(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap,posY+halfCellSize);
        CV::polygonFill(x_v,y_v,6); //i
    }
    void Display16::drawA2(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap*2,posY+cellSize);
        CV::polygonFill(x_h,y_h,6); // a2
    }
    void Display16::drawA1(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX,posY+cellSize);
        CV::polygonFill(x_h,y_h,6); // a1
    }
    void Display16::drawG2(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap*2,posY+halfCellSize);
        CV::polygonFill(x_h,y_h,6); // g2
    }
    void Display16::drawG1(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX,posY+halfCellSize);
        CV::polygonFill(x_h,y_h,6); // g1
    }
    void Display16::drawC(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+cellSize+gap*3,posY);
        CV::polygonFill(x_v,y_v,6); // c
    }
    void Display16::drawL(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+gap+halfCellSize,posY);
        CV::polygonFill(x_v,y_v,6); //L
    }
    void Display16::drawD2(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap*2,posY);
        CV::polygonFill(x_h,y_h,6); //d2
    }
    void Display16::drawJ(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX+halfCellSize+gap*2,posY+cellSize);
        CV::polygonFill(x_dl,y_dl,6); //j
    }
    void Display16::drawK(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX,posY+halfCellSize);
        CV::polygonFill(x_dl,y_dl,6); //k
    }
    void Display16::drawH(int r = 1, int g = 0, int b = 0){
        CV::color(r,g,b);
        CV::translate(posX,posY+cellSize);
        CV::polygonFill(x_dr,y_dr,6); //h
    }

    void Display16::DrawDigit(int idx){
        if(idx == 10 || idx==32 || idx == 58) return;
        if(idx > 57){
            idx -= 55;
        }else{
            idx-=48;
        }
        if((BinaryTable[idx] >> 15 & 1) == 1)
        {
                drawA1();
        }
        if((BinaryTable[idx]>> 14 & 1) == 1)
        {
                drawA2();
        }
        if((BinaryTable[idx]>> 13 & 1) == 1)
        {
                drawB();
        }
        if((BinaryTable[idx]>> 12 & 1) == 1)
        {
                drawC();
        }
        if((BinaryTable[idx]>> 11 & 1) == 1)
        {
                drawD2();
        }
        if((BinaryTable[idx]>> 10 & 1) == 1)
        {
                drawD1();
        }
        if((BinaryTable[idx]>> 9 & 1) == 1)
        {
                drawE();
        }
        if((BinaryTable[idx]>> 8 & 1) == 1)
        {
                drawF();
        }
        if((BinaryTable[idx]>> 7 & 1) == 1)
        {
                drawH();
        }
        if((BinaryTable[idx]>> 6 & 1) == 1)
        {
                drawI();
        }
        if((BinaryTable[idx]>> 5 & 1) == 1)
        {
                drawJ();
        }
        if((BinaryTable[idx]>> 4 & 1) == 1)
        {
                drawG1();
        }
        if((BinaryTable[idx]>> 3 & 1) == 1)
        {
                drawG2();
        }
        if((BinaryTable[idx]>> 2 & 1) == 1)
        {
                drawK();
        }
        if((BinaryTable[idx]>> 1 & 1) == 1)
        {
                drawL();
        }
        if((BinaryTable[idx]>> 0 & 1) == 1)
        {
                drawM();
        }
    }


    void Display16::DrawClock(int number){
        int idx = number;
        int auxPosX = posX;
        int auxPosY = posY;
        auto givemetime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char* time = ctime(&givemetime);
        for(int i=0;i<strlen(time);i++){
            posX += 80;
            DrawDigit((int)toupper(time[i]));

        }
        posX = auxPosX;
        posY = auxPosY;
    }

    void Display16::Anima(int number){

        DrawClock(number);


    }
