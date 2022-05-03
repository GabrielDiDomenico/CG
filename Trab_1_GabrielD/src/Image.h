#ifndef IMAGE_H
#define IMAGE_H

#include "gl_canvas2d.h"
#include "Bmp.h"
#include <iostream>
#include <tgmath.h>
#include <vector>


class Image{



public:

    Image(const char *imgName, int ix, int iy);

    int getImgHeight();

    int getImgWidth();

    unsigned char* getImgData();

    int getImgBPL();

    void calculateDeltaXY(int mx, int my);

    void printImage(int mx, int my);

    bool Colidiu(int mx, int my);

    const char *getName();

    bool& isSelected();

    bool& isActive();

    bool& isVFlipped();

    bool& isHFlipped();

    void setActive(bool value);

    void setSelected(bool value);

    void setXWithDelta(int value);

    void setYWithDelta(int value);

    int getX();

    int getY();

    bool isReady();

    void flipVImg(bool value);

    void flipHImg(bool value);

    int getChannel(int i);

    void setChannel(int v[3]);

    void setGreyscale(bool value);

    bool& isGreyscale();

    void resizeImage(float scale);

    void resetResImg();

private:
    Bmp *bmp;
    unsigned char *data;
    int bytesPerLine;
    const char *name;
    int x,y,dx,dy;
    float width,height;
    bool active, selected, flipV, flipH, greyscale;
    int channel[3] = {1, 1, 1};

};

#endif
