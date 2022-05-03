#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "gl_canvas2d.h"

class Histogram{

public:
    Histogram(int _x, int _y){

        x = _x;
        y = _y;
        valueR = 0;
        valueG = 0;
        valueB = 0;
        valueL = 0;
        redActive = false;
        greenActive = false;
        blueActive = false;
        greyActive = false;

    }

void histogramGraph(int _imgWidth, int _imgHeight, unsigned char arrImg[]){
    imgWidth = _imgWidth;
    imgHeight = _imgHeight;
    int bytesPerLine = (3 * (imgWidth + 1) / 4) * 4;

    if(greyActive){
        histogramWindow('g');
        CV::translate(1135,280);
        for(float i=0.0;i<1.0;i+=0.01){
            valueL = 0;
            for(float y=0;y<imgHeight;y++)
            for(float x=0;x<imgWidth*3;x=x+3){
                int pos = y*bytesPerLine + x;
                float grey = ((0.3 * arrImg[pos+1]) + (0.59 * arrImg[pos+2]) + (0.11 * arrImg[pos+0]));
                float greyResult = (round((grey/255) * 100) / 100)-i;
                valueL = greyResult >= 0.0 && greyResult <= 0.001 ? valueL+1 : valueL;

            }
            CV::color(0,0,0);
            CV::line((float)x+(i*100),(float)y,(float)x+(i*100),(float)y+valueL*0.02);
        }


    }else{
        histogramWindow('n');
        CV::translate(1130,280);
        for(int i=0;i<255;i++){
            valueR = 0;
            valueG = 0;
            valueB = 0;
            for(float y=0;y<imgHeight;y++)
            for(float x=0;x<imgWidth*3;x=x+3){
                int pos = y*bytesPerLine + x;

                if(redActive)
                valueR = (int)arrImg[pos] == i ? valueR+1 : valueR;
                if(greenActive)
                valueG = (int)arrImg[pos+1] == i ? valueG+1 : valueG;
                if(blueActive)
                valueB = (int)arrImg[pos+2] == i ? valueB+1 : valueB;
            }
            CV::color(1,0,0);
            if(redActive)
            CV::line((float)x+i,(float)y,(float)x+i,(float)y+valueR*0.05);
            CV::color(0,1,0);
            if(greenActive)
            CV::line((float)x+i,(float)y,(float)x+i,(float)y+valueG*0.05);
            CV::color(0,0,1);
            if(blueActive)
            CV::line((float)x+i,(float)y,(float)x+i,(float)y+valueB*0.05);
        }

    }

}

    void histogramWindow(char g){

        CV::translate(1310,500);
        CV::color(1,1,1);
        CV::rectFill(0,0,500,500);
        CV::color(0,0,0);
        CV::rectFill(120,70,376,72);
        CV::rectFill(120,80,115,82); //0
        CV::rectFill(120,130,115,132); //1000
        CV::rectFill(120,180,115,182); //2000
        CV::rectFill(120,230,115,232); //3000
        CV::rectFill(120,280,115,282); //4000
        CV::rectFill(120,330,115,332); //5000
        CV::text(105,82,"0");
        CV::text(75,132,"1000");
        CV::text(75,182,"2000");
        CV::text(55,362,"Pixel Color");
        CV::text(75,232,"3000");
        CV::text(75,282,"4000");
        CV::text(75,332,"5000");
        if(g == 'g'){
            CV::rectFill(120,70,122,350);
            CV::rectFill(126,70,128,65); //0.0
            CV::rectFill(176,70,178,65); //0.2
            CV::rectFill(226,70,228,65); //0.4
            CV::rectFill(276,70,278,65); //0.6
            CV::rectFill(326,70,328,65); //0.8
            CV::rectFill(370,70,372,65); //1.0
            CV::text(128,55,"0.0");
            CV::text(178,55,"0.2");
            CV::text(182,35,"Greyscale value");
            CV::text(228,55,"0.4");
            CV::text(278,55,"0.6");
            CV::text(328,55,"0.8");
            CV::text(372,55,"1.0");
        }else{
            CV::rectFill(120,70,122,350);
            CV::rectFill(120,70,122,65); //0
            CV::rectFill(170,70,172,65); //50
            CV::rectFill(220,70,222,65); //100
            CV::rectFill(270,70,272,65); //150
            CV::rectFill(320,70,322,65); //200
            CV::rectFill(370,70,372,65); //250
            CV::text(122,55,"0");
            CV::text(172,55,"50");
            CV::text(222,55,"100");
            CV::text(202,35,"Color Value");
            CV::text(272,55,"150");
            CV::text(322,55,"200");
            CV::text(372,55,"250");
        }


    }

    void setRedActive(bool value){ redActive = value;}
    void setGreenActive(bool value){ greenActive = value;}
    void setBlueActive(bool value){ blueActive = value;}
    void setGreyActive(bool value){ greyActive = value;}

    bool getRedActive(){ return redActive;}
    bool getGreenActive(){ return greenActive;}
    bool getBlueActive(){ return blueActive;}
    bool getGreyActive(){ return greyActive;}



private:
    int imgWidth, imgHeight, x, y;
    unsigned char* arrImg;
    int valueR, valueG, valueB, valueL;
    bool redActive, greenActive, blueActive, greyActive;

};

#endif
