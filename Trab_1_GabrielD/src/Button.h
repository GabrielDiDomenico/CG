#ifndef __BOTAO_H__
#define __BOTAO_H__

#include <functional>
#include "gl_canvas2d.h"


class Button{


public:
  Button(float _x, float _y, float _larg, float _alt, char *_label, std::function<void()> _funct);

  void Render();

  //recebe as coordenadas do mouse para tratar clique ou detectar quando o mouse esta em cima do botao
  bool Colidiu(int mx, int my);

  void doFunction();

private:
    float altura, largura, x, y;
    char label[100];
    std::function<void()> funct;


};

#endif
