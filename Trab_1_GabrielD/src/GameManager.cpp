#include "GameManager.h"

GameManager::GameManager(){

    imgManager = new ObjectManager<Image>();
    imgManager->addObject(new Image(".//gl_1_canvasGlut//resources//img1.BMP",20,20));
    imgManager->addObject(new Image(".//gl_1_canvasGlut//resources//img2.BMP",200,20));
    imgManager->addObject(new Image(".//gl_1_canvasGlut//resources//img3.BMP",540,20));
    histo = new Histogram(300,300);
    buttonManager = new ObjectManager<Button>();
    buttonManager->addObject(new Button(20, 865, 140, 50, "Img1",  [this]() { activeImage(".//gl_1_canvasGlut//resources//img1.BMP"); }));
    buttonManager->addObject(new Button(20, 810, 140, 50, "Img2", [this]() { activeImage(".//gl_1_canvasGlut//resources//img2.BMP"); }));
    buttonManager->addObject(new Button(20, 755, 140, 50, "Img3", [this]() { activeImage(".//gl_1_canvasGlut//resources//img3.BMP"); }));
    buttonManager->addObject(new Button(180, 865, 140, 50, "flip", [this]() { flipImages(); }));
    buttonManager->addObject(new Button(180, 810, 140, 50, "channel", [this]() { changeChannel(); }));
    buttonManager->addObject(new Button(180, 755, 140, 50, "grey", [this]() { setGreyscale(); }));
    buttonManager->addObject(new Button(360, 865, 140, 50, "resize reset", [this]() { resetResImg(); }));
    buttonManager->addObject(new Button(360, 810, 140, 50, "resize 50%", [this]() { resizeImage(0.5); }));
    buttonManager->addObject(new Button(360, 755, 140, 50, "resize 25%", [this]() { resizeImage(0.25); }));
    buttonManager->addObject(new Button(540, 865, 140, 50, "HistogramR", [this]() { setReadyHistogram('r'); }));
    buttonManager->addObject(new Button(540, 810, 140, 50, "HistogramG", [this]() { setReadyHistogram('g'); }));
    buttonManager->addObject(new Button(540, 755, 140, 50, "HistogramB", [this]() { setReadyHistogram('b'); }));
    buttonManager->addObject(new Button(720, 865, 140, 50, "HistogramL", [this]() { setReadyHistogram('l'); }));
    buttonManager->addObject(new Button(720, 810, 140, 50, "Close Histogram", [this]() { closeHistogram(); }));
    display16 = new Display16();
    imgMovEnable = false;

}

void GameManager::printHistogram(){
    if(histogramIsReady){
        for(Image* i : imgManager->Objects){
            if(i->isReady()){
                histo->histogramGraph(i->getImgWidth(), i->getImgHeight(), i->getImgData());
            }
        }

    }
}

void GameManager::setReadyHistogram(char c){

    histogramIsReady = true;
    switch(c){
        case 'r':
            histo->setGreyActive(false);
            histo->getRedActive() == true ? histo->setRedActive(false) :  histo->setRedActive(true);
            break;
        case 'g':
            histo->setGreyActive(false);
            histo->getGreenActive() == true ? histo->setGreenActive(false) : histo->setGreenActive(true);
            break;
        case 'b':
            histo->setGreyActive(false);
            histo->getBlueActive() == true ? histo->setBlueActive(false) : histo->setBlueActive(true);
            break;
        case 'l':
            histo->getGreyActive() == true ? histo->setGreyActive(false) : histo->setGreyActive(true);
            break;
    }

}

void GameManager::closeHistogram(){
    histogramIsReady = false;
}

void GameManager::changeChannel(){

    for(Image* i : imgManager->Objects){
        if(i->isSelected()){
            if(i->getChannel(0) && i->getChannel(1)){
                int aux[3] = {1,0,0};
                i->setChannel(aux);
            }
            else if(i->getChannel(0)){
                int aux[3] = {0,1,0};
                i->setChannel(aux);
            }
            else if(i->getChannel(1)){
                int aux[3] = {0,0,1};
                i->setChannel(aux);
            }
            else if(i->getChannel(2)){
                int aux[3] = {1,1,1};
                i->setChannel(aux);
            }

        }

    }
}

void GameManager::setGreyscale(){
    for(Image* i : imgManager->Objects){

        if(i->isSelected() && i->isGreyscale()){
            i->setGreyscale(false);
        }else if(i->isSelected() && !i->isGreyscale()){
            i->setGreyscale(true);
        }

    }
}

void GameManager::resetImages(){
    for(int i=0;i<imgManager->getObjCount();i++)
        imgManager->getObjectById(i)->setSelected(false);
}

void GameManager::activeImage(const char* imgName){
    for(Image* i : imgManager->Objects){
        if(strcmp(imgName, i->getName()) == 0)
            if(i->isActive()){
                i->setActive(false);
            }
            else{
                i->setActive(true);
            }
    }

}

void GameManager::flipImages(){

    for(Image* i : imgManager->Objects){

        if(i->isSelected() && !i->isFlipped()){
            i->flipImg(true);
        }
        else if(i->isSelected() && i->isFlipped()){
            i->flipImg(false);
        }
    }

}



void GameManager::buttonListener(int x, int y){
    for(Button* b : buttonManager->Objects){
        if(b->Colidiu(x, y)){
            b->doFunction();
        }

    }
}

void GameManager::imageListener(int x, int y){
    for(int i=0;i<imgManager->getObjCount();i++){
        if( imgManager->getObjectById(i)->Colidiu(x, y) ){
            resetImages();
            imgMovEnable = true;
            imgManager->getObjectById(i)->setSelected(true);
            imgManager->getObjectById(i)->calculateDeltaXY(x,y);
        }
    }
}

void GameManager::mouseRelease(int x, int y){
    if(imgMovEnable)
    for(int i=0;i<imgManager->getObjCount();i++){
        if(imgManager->getObjectById(i)->isSelected()){
            imgManager->getObjectById(i)->setXWithDelta(x);
            imgManager->getObjectById(i)->setYWithDelta(y);
        }

    }
    imgMovEnable = false;
}

void GameManager::printImages(int x, int y){
    for(Image* i : imgManager->Objects){
        if(i->isReady() && imgMovEnable){
            i->printImage(x, y);
        }
        else{
            if(i->isActive())
                i->printImage(0,0);
        }

    }
}

void GameManager::resetResImg(){
    for(Image* i : imgManager->Objects){

        if(i->isSelected()){
            i->resetResImg();
        }

    }
}

void GameManager::resizeImage(float scale){
    histogramIsReady = false;
    for(Image* i : imgManager->Objects){

        if(i->isSelected()){
            i->resizeImage(scale);
        }

    }
}

void GameManager::printButtons(){
    for(int i=0;i<buttonManager->getObjCount();i++){
        buttonManager->getObjectById(i)->Render();
    }
}
