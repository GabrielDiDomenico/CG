#include "Button.h"

Button::Button(float _x, float _y, float _larg, float _alt, char *_label, std::function<void()> _funct)
{
     altura  = _alt;
     largura = _larg;
     x = _x;
     y = _y;
     strcpy(label, _label);
     funct = _funct;

}

void Button::Render()
{
    CV::color(0, 1, 0);
    CV::rectFill(x, y, x + largura, y + altura);
    CV::color(0, 0, 0);
    CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro.
}

//recebe as coordenadas do mouse para tratar clique ou detectar quando o mouse esta em cima do botao
bool Button::Colidiu(int mx, int my)
{
    if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) )
    {
      return true;
    }
    return false;
}

void Button::doFunction(){ funct();}
