#include "Image.h"

Image::Image(const char *imgName, int ix, int iy){

    bmp = new Bmp(imgName);
    bmp->convertBGRtoRGB();
    data = bmp->getImage();
    bytesPerLine = (3 * (bmp->getWidth() + 1) / 4) * 4;
    name = imgName;
    active = false;
    selected = false;
    flip = false;
    x = ix;
    y = iy;
    dx = 0;
    dy = 0;
    greyscale = false;
    width = (float)bmp->getWidth();
    height = (float)bmp->getHeight();


}

int Image::getImgHeight(){ return bmp->getHeight(); }
int Image::getImgWidth(){ return bmp->getWidth(); }
unsigned char* Image::getImgData(){ return data; }
int Image::getImgBPL(){ return bytesPerLine; }

void Image::calculateDeltaXY(int mx, int my){
    dx = mx - x;
    dy = my - y;
}

void Image::resetResImg(){
    delete[] data;
    bmp = new Bmp(name);
    bmp->convertBGRtoRGB();
    bytesPerLine = (3 * (bmp->getWidth() + 1) / 4) * 4;
    data = new unsigned char[bytesPerLine*bmp->getHeight()];
    data = bmp->getImage();
    height = (float)bmp->getHeight();
    width = (float)bmp->getWidth();
}

void Image::resizeImage(float scale){


    int testHeight = height * scale;
    int testWidth = width * scale;
    if (testHeight < bmp->getHeight()*0.25 || testWidth < bmp->getWidth()*0.25){

        return;
    }
    height *= scale;
    width *= scale;
    int resBytesPerLine =(3 * (width + 1) / 4) * 4;

    unsigned char* resizedData = new unsigned char[resBytesPerLine*(int)height];

    for(float y=0;y<height;y++)
    for(float x=0;x<width*3;x=x+3){
        int resizedPos = y*resBytesPerLine + x;
        int originalY = std::floor(y*(1/scale));
        int originalX = std::floor(x*(1/scale));
        int pos = originalY * bytesPerLine + originalX;
        resizedData[resizedPos] = data[pos];
        resizedData[resizedPos+1] = data[pos+1];
        resizedData[resizedPos+2] = data[pos+2];
    }
    bytesPerLine = resBytesPerLine;
    delete[] data;
    data = new unsigned char[bytesPerLine*(int)height];
    for(int i=0;i<bytesPerLine*(int)height;i++)
        data[i] = resizedData[i];

}

void Image::printImage(int mx = 0, int my = 0){
    if(mx > 0 || my > 0)
        CV::translate(mx - dx,my - dy);
    else
        CV::translate(x,y);



    for(float y=0;y<height;y++)
    for(float x=0;x<width*3;x=x+3){
        if(flip){

            int pos = y*bytesPerLine + (bytesPerLine - 1 - x);

            if(greyscale){
                float grey = ((0.3 * data[pos+1]) + (0.59 * data[pos+2]) + (0.11 * data[pos+0]));
                CV::color(grey/255,grey/255,grey/255);
            }
            else{
                CV::color((float)(data[pos+1])/255*(channel[0]),(float)(data[pos+2]*channel[1])/255,(float)(data[pos]*channel[2])/255);
            }

            CV::point(x/3,y);
        }else{
            int pos = y*bytesPerLine + x;
            if(greyscale){

                float grey = ((0.3 * data[pos+1]) + (0.59 * data[pos+2]) + (0.11 * data[pos+0]));

                CV::color(grey/255,grey/255,grey/255);
            }
            else{

               CV::color((float)(data[pos]*channel[0])/255,(float)(data[pos+1]*channel[1])/255,(float)(data[pos+2]*channel[2])/255);

            }

            //CV::rectFill(x/3,y,(x/3)+1,y+1);
            CV::point(x/3,y);
        }

    }
}

bool Image::Colidiu(int mx, int my){
  if( mx >= x && mx <= (x + width) && my >= y && my <= (y + height) )
  {
      return true;
  }
  return false;
}

const char *Image::getName(){ return name;}

bool& Image::isSelected(){ return selected;}

bool& Image::isActive(){ return active;}

bool& Image::isFlipped(){ return flip;}

bool& Image::isGreyscale() {return greyscale;}

void Image::setActive(bool value){ active = value;}

void Image::setSelected(bool value){ selected = value;}

void Image::setXWithDelta(int value){ x = value - dx;}

void Image::setYWithDelta(int value){ y = value - dy;}

int Image::getX(){ return x;}

int Image::getY(){ return y;}

bool Image::isReady(){
    if(active){
        if(selected){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Image::flipImg(bool value){ flip = value;}

int Image::getChannel(int i) { return channel[i];}

void Image::setChannel(int v[3]) {
     channel[0] = v[0];
     channel[1] = v[1];
     channel[2] = v[2];
}

void Image::setGreyscale(bool value){ greyscale = value;}


