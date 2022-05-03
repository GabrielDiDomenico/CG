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

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa função com poucas linhas de codigo.
void render()
{

    CV::clear(0,0,0);

    GM->printButtons();

    GM->printImages(mouseX, mouseY);

    GM->printHistogram();


}

//funcao chamada toda vez que uma tecla for pressionada.
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

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
    mouseY = y;



    if( state == 0 ) {//clicou


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

    CV::init(&SWIDTH, &SHEIGHT, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    CV::run();
}
