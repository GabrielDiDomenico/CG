#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>

#include "Image.h"
#include "Button.h"
#include "Display16.h"
#include "ObjectManager.h"
#include "Histogram.h"
#include "gl_canvas2d.h"

class GameManager{

public:

    GameManager();

    void changeChannel();

    void setGreyscale();

    void resetImages();

    void activeImage(const char* imgName);

    void flipImages();

    void buttonListener(int x, int y);

    void imageListener(int x, int y);

    void mouseRelease(int x, int y);

    void printImages(int x, int y);

    void printButtons();

    void resizeImage(float scale);

    void resetResImg();

    void printHistogram();

    void setReadyHistogram(char c);

    void closeHistogram();

private:

    ObjectManager<Image> *imgManager;
    ObjectManager<Button> *buttonManager;
    Display16 *display16;
    bool imgMovEnable,histogramIsReady;
    Histogram* histo;


};

#endif
