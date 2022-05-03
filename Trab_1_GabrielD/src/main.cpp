/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 3
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.


#include "GameManager.h"

int SWIDTH = 1920;
int SHEIGHT = 1080;
int mouseX, mouseY;

GameManager* GM = NULL;


void render()
{

    CV::clear(0,0,0);

    GM->printButtons();

    GM->printImages(mouseX, mouseY);

    GM->printHistogram();

    GM->printDisplay16();

}


void keyboard(int key)
{
    printf("\nTecla: %d" , key);


    switch(key)
    {
        case 27:
            exit(0);
            break;
    }
}

void keyboardUp(int key)
{
    printf("\nLiberou: %d" , key);
}


void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    mouseX = x;
    mouseY = y;



    if( state == 0 ) {


        GM->buttonListener(x,y);

        GM->imageListener(x,y);


    }

    if(state == 1){

        GM->mouseRelease(x,y);
    }
}

int main(void)
{

    GM = new GameManager();

    CV::init(&SWIDTH, &SHEIGHT, "Trabalho 1 Gabriel Di Domenico");
    CV::run();
}
