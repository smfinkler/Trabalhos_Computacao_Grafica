/*********************************************************************
//
//  Instruções:
//	  Ao abrir o programa, existe um menu na lateral esquerda disponibilizando as seguintes ações:
//    1 - QUADRADO: Botão que cria um quadrado no meio da tela
//    2 - TRIANGULO: Botão que cria um triângulo no meio da tela
//    3 - CIRCULO: Botão que cria um círculo no meio da tela
//    4 - POLIGONO: Botão para criar um Poligono no meio da tela de acordo com o contador exibido no display logo abaixo
//    5 - + e -: Botões para incrementear e decrementar o contador de lados para criação de polígono do botão POLIGONO
//    6 - ROTACIONAR ESQ: Rotaciona figura selecionada para a esquerda
//    7 - ROTACIONAR DIR: Rotaciona figura selecionada para a direita
//    8 - LARGURA+: Aumenta a largura da figura selecionada
//    9 - LARGURA-: Diminui a largura da figura selecionada
//    10 - ALTURA+: Aumenta a altura da figura selecionada
//    11 - ALTURA-: Diminui a altura da figura selecionada
//    12 - TRAZER PARA TRAS: Traz a figura para trás na tela
//    13 - TRAZER PARA FRENTE: Traz a figura para a frente na tela
//    14 - EXCLUIR: Exclui a figuraa selecionada da tela
//    15 - SALVAR: Salva o desenho atual em um arquivo
//
//    Para selecionar uma figura basta clicar sobre ela
//    Havendo alguma figura selecionada, ao clicar na paleta de cores, essa figura recebe a cor clicada.
//    Havendo alguma figura selecionada é possível movê-la com as setas do teclado e com o mouse (segurando e arrastando)
//    A tecla ESC encerra o programa
// *********************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include "gl_canvas2d.h"
#include "Manager.h"
#include "Botao.h"

using namespace std;

int opcao  = 50;
int screenWidth = 1080, screenHeight = 720; //HD: largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //Variaveis globais do mouse para poder exibir dentro da render().
list<Botao*> botoes; //Lista de Botões do Menu
list<Figura*> figuras; //Lista de Figuras
Figura *figura_selecionada = nullptr; //Figura selecionada
Retangulo *ret = nullptr;
bool mover_figura = false, clicou_branco = false; //mover figura true significa que a figura esta sendo segurada. clicou_branco true significa que não clicou em nenhum botão ou figura
char char_lados_poligono[2] = "4"; //char para exibir no display de número de lados para polígono

void DrawMouseScreenCoords()
{
    char str[100];
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    CV::text(10,300, str);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
    CV::text(10,320, str);
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa função com poucas linhas de codigo.
void render(){

    for(auto it : botoes){
        it->render();
    }
    for(auto it : figuras){
        it->render();
    }

    //próximas 5 linhas para exibir o display de número de lados para polígono
    CV::color(0.5, 0.75, 0.5);
    CV::rectFill(ALTURA_BOTAO*2+2, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*5)-5, LARGURA_BOTAO, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*5)-5+ALTURA_BOTAO);
    CV::color(0);
    sprintf(char_lados_poligono, "%d", lados_poligono);
    CV::text(120, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*5)+8, char_lados_poligono);
}



//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key){

   if( key < 200 ){
      opcao = key;
   }

    switch(key){
        //esc fecha o programa
        case 27:
            exit(0);
            break;

        //seta para a esquerda
        case 200:
            figura_selecionada->move_figura(figura_selecionada->x-10,figura_selecionada->y);
            break;

        //seta para cima
        case 201:
            figura_selecionada->move_figura(figura_selecionada->x,figura_selecionada->y+10);
            break;

        //seta para a direita
        case 202:
            figura_selecionada->move_figura(figura_selecionada->x+10,figura_selecionada->y);
            break;

        //seta para baixo
        case 203:
            figura_selecionada->move_figura(figura_selecionada->x,figura_selecionada->y-10);
            break;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key){
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y){
    mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
    mouseY = y;

    if(state==0){
        clicou_branco = true;
        for(auto it = botoes.begin(); it != botoes.end(); it++){
            if((*it)->Colidiu(x, y)){
                (*it)->action(&figuras, figura_selecionada);
                clicou_branco = false;
                break;
            }
        }

        //reverse iterator para percorrer a lista ao contrário
        if(!figuras.empty()){
            for(auto revIt = figuras.rbegin(); revIt != figuras.rend(); ++revIt){
                if((*revIt)->Colidiu(x, y)){
                    figura_selecionada = (*revIt);
                    mover_figura = true;
                    clicou_branco = false;
                    break;
                }
                mover_figura = false;
            }
        }
        if(clicou_branco){
            figura_selecionada = nullptr;
        }
    }else if(state == 1){
        mover_figura = false;
    }
    if(mover_figura){
        figura_selecionada->move_figura(x,y);
    }
}

//lê as figuras guardadas no arquivo binário
void inicializa_Figuras(){
    fstream  my_file("smfinkler/figuras.gr", ios::in | ios::binary);
    float x,y,altura, largura, rotacao,r,g,b;
    int tipo;

    while(my_file.good()){
        my_file.read((char*)&tipo, sizeof(tipo));
        if(my_file.good()){
            my_file.read((char*)&x, sizeof(x));
            my_file.read((char*)&y, sizeof(y));
            my_file.read((char*)&largura, sizeof(largura));
            my_file.read((char*)&altura, sizeof(altura));
            my_file.read((char*)&rotacao, sizeof(rotacao));
            my_file.read((char*)&r, sizeof(r));
            my_file.read((char*)&g, sizeof(g));
            my_file.read((char*)&b, sizeof(b));

            switch(tipo){
                case 1:
                    figuras.push_back(new Retangulo(tipo, x, y, largura, altura, rotacao, r,g,b));
                    break;
                case 2:
                    figuras.push_back(new Triangulo(tipo, x, y, largura, altura, rotacao, r,g,b));
                    break;
                case 3:
                    figuras.push_back(new Circulo(tipo, x, y, largura, altura, rotacao, r,g,b));
                    break;
                default:
                    figuras.push_back(new Poligono(tipo, x, y, largura, altura, rotacao, r,g,b));
            }
        }
    }
}

int main(void){
   CV::init(&screenWidth, &screenHeight, "T1-smfinkler");
   inicializa_Botoes(&botoes);
   inicializa_Figuras();
   CV::run();
}
