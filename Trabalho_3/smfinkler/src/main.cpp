/*********************************************************************
//  INSTRU��ES:
//	  Ao abrir o programa, existe um menu com as seguintes a��es:
//    1 - NEW GAME
//    2 - UNLIMITED ARROWS GAME
//    3 - EXIT
//
//    A op��o NEW GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com 10 proj�teis
//    A op��o UNLIMITED ARROWS GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com proj�teis infinitos
//    A op��o EXIT encerra o jogo
//
//    Os objetos do cen�rio do jogo s�o de dois tipo (BALOES e OBSTACULOS)
//    CIRCULOS: BALOES
//    RETANGULOS: OBSTACULOS
//    0- Obstaculo inquebravel (VERMELHO) - Destr�i a flecha e � indestrut�vel
//    1- Obstaculo quebravel (CINZA ESCURO) - Destr�i a flecha e � destrut�vel
//    2- Balao normal (VERDE) - Bal�o comum que explode ao ser atingido
//    3- Balao forte (AMARELO ESCURO) - Bal�o que precisa ser atingido 2x para explodir
//    4- Balao com dardo extra (ROXO) - Bal�o que acrescenta um proj�til, explode ao ser atingido
//    5- Balao congelante (CIANO) - Bal�o indestrut�vel que congela seus vizinhos (esq e dir) ao ser atingido
//    6- Balao indestrutivel (CIANO) - Bal�o que n�o pode ser destru�do (o proj�til atravessa)
//
//    O objetivo do jogo � eliminar a maior quantidade de bal�es poss�vel com o n�mero de proj�teis disp�n�vel (10 ou infinito)
//    Para lan�ar um proj�til, a for�a que ele ser� lan�ado depende de quanto se segura o mouse (a for�a aumenta at� um m�ximo e depois diminui at� um m�nimo, asssim sucessivamente)
//    Ap�s iniciar partida, � poss�vel alternar entre as duas fases(cen�rios) com o bot�o ESPA�O, contanto que seja no in�cio da fase(10 projeteis) ou final(0 proj�teis)
//    � poss�vel sair da fase e voltar ao MENU a qualquer momento, com a tecla ESC
//    � poss�vel encerrar o jogo com a tecla F4
// *********************************************************************/

//TIPOS DE BAL�O    :
  //0- Obst�culo maci�o
  //1- Obst�culo quebr�vel
  //2- Bal�o normal
  //3- Bal�o forte
  //4- Bal�o com dardo extra
  //5- Bal�o congelante
  //6- Bal�o indestrut�vel

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <list>
#include <string>

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include "gl_canvas2d.h"
#include "Jogo.h"
#include "Botao.h"

using namespace std;

int opcao = 50;
int screenWidth = 1080, screenHeight = 720; //HD: largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //Variaveis globais do mouse para poder exibir dentro da render().

Jogo* jogo;
char char_num_projeteis[1] = "";
list<Botao*> botoes; //lista de bot�es
bool jogo_iniciado = false; //vari�vel que diz se o jogo foi iniciado ou se estamos no menu
bool aux=0; //vari�vel utilizada para que projetil n�o seja lan�ada com clique no menu

//declara��o das fun��es
void inicializa_Objetos_Fase1();
void inicializa_Objetos_Fase2();


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
//Deve-se manter essa fun��o com poucas linhas de codigo.
void render(){

    if(!botao){
        for(auto it : botoes){
            it->render();
        }
    }else if(botao==3){
        exit(0);
    }
    //0- Obst�culo maci�o
    //1- Obst�culo quebr�vel
    //2- Bal�o normal
    //3- Bal�o forte
    //4- Bal�o com dardo extra
    //5- Bal�o congelante
    //6- Bal�o indestrut�vel
    if(botao!=0){
        CV::text(25,700, "CIRCULOS: BALOES");
        CV::text(25,680, "RETANGULOS: OBSTACULOS");
        CV::text(25,660, "0- Obstaculo inquebravel (VERMELHO)");
        CV::text(25,640, "1- Obstaculo quebravel (CINZA ESCURO)");
        CV::text(25,620, "2- Balao normal (VERDE)");
        CV::text(25,600, "3- Balao forte (AMARELO ESCURO)");
        CV::text(25,580, "4- Balao com dardo extra (ROXO)");
        CV::text(25,560, "5- Balao congelante (CIANO)");
        CV::text(25,540, "6- Balao indestrutivel (CIANO)");

        CV::text(280,75, "A forca do projetil esta relacionada a quanto se segura o clique no lancamento");
        CV::text(280,50, "ESC volta para menu");
        CV::text(280,25, "ESPACO troca de fase com 0 ou 10 projeteis");

        CV::rectFill(0,0,50,50);
        CV::line(50,50, mouseX/4, mouseY/4);

        jogo->render();

        sprintf(char_num_projeteis, "%d", jogo->num_projeteis);
        CV::text(100,25, "Projeteis:");
        CV::text(220,25, char_num_projeteis);
    }
    if(botao!=0){
        jogo_iniciado=true;
    }
}



//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key){

   if( key < 200 ){
      opcao = key;
   }

    switch(key){
        //esc volta para o menu
        case 27:
            jogo->fase=0;
            inicializa_Objetos_Fase1();
            jogo_iniciado = false;
            botao = 0;
            aux = false;
            break;

        //espa�o
        case 32:
            if (jogo->num_projeteis==10 || jogo->num_projeteis==9 || jogo->num_projeteis==0){
                if(jogo->fase==0){
                    jogo->fase=1;
                    jogo->num_projeteis=10;
                    inicializa_Objetos_Fase2();
                }else{
                    jogo->fase=0;
                    jogo->num_projeteis=10;
                    inicializa_Objetos_Fase1();
                }
            }
            break;

        //F4 encerra programa
        case 104:
            exit(0);
            break;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key){
   printf("\nLiberou: %d" , key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
//aqui � tratado os cliques para lan�amento de proj�til(for�a), assim como clique em bot�es no menu
void mouse(int button, int state, int wheel, int direction, int x, int y){
    mouseX = x;
    mouseY = y;

    if(state==0){
        if(botao==0){
            for(auto it = botoes.begin(); it != botoes.end(); it++){
                if((*it)->Colidiu(x, y)){
                    (*it)->action();
                    break;
                }
            }
        }
        jogo->aceleracao=0.001;
        jogo->mouse_clicado=true;
    }else if(state == 1){
        jogo->mouse_clicado=false;
        printf("\nAceleracao = %f", jogo->aceleracao);
        if(jogo->num_projeteis>0){
            if(jogo->projetil==NULL && botao!=0){
                if(aux){
                    jogo->projetil = new Projetil(jogo->aceleracao, mouseX, mouseY);
                    if(botao!=2){
                        jogo->num_projeteis--;
                    }
                }
                aux=true;
            }
        }
    }
}

//fun��o que prepara o cen�rio para a fase inicial do jogo
void inicializa_Objetos_Fase1(){
    int num_linhas=12, total_baloes=0, index=0, teste=0;
    int obj_por_linha[num_linhas] = {1,5,7,9,9,11,11,13,13,9,7,3};
    jogo->num_projeteis=10;
    for(int i=0; i<num_linhas; i++){
        total_baloes+=obj_por_linha[i];
    }
    jogo->obj = new Objeto*[total_baloes];

    for(int i=0; i<num_linhas; i++){
        if(i!=0){
            teste += (obj_por_linha[i]-obj_por_linha[i-1])/2;
        }
        for(int j=0; j<obj_por_linha[i]; j++){
            jogo->obj[index] = new Balao(2, 1, 540+(j*30)-teste*30, 675-(i*45), 10, 15, 0, 0, 0.9, 0);
            index++;
        }
    }

    jogo->obj[26]->troca_tipo(4);
    jogo->obj[26]->troca_cor(0.8, 0, 0.8);

    jogo->obj[83]->troca_tipo(5);
    jogo->obj[83]->troca_cor(0,1,1);

    jogo->obj[79] = new Obstaculo(0, 1, 540+(0*30)-4*30, 675-(9*45), 10, 15, 0, 1, 0, 0);
    jogo->obj[87] = new Obstaculo(0, 1, 540+(8*30)-4*30, 675-(9*45), 10, 15, 0, 1, 0, 0);
}

//fun��o que prepara o cen�rio para a fase alternativa do jogo
void inicializa_Objetos_Fase2(){
    int num_linhas=12, total_baloes=0, index=0, teste=0;
    int obj_por_linha[num_linhas] = {5,7,9,11,11,11,11,11,9,9,9,9};
    jogo->num_projeteis=10;
    for(int i=0; i<num_linhas; i++){
        total_baloes+=obj_por_linha[i];
    }
    printf("Total = %d", total_baloes);
    jogo->obj = new Objeto*[total_baloes];

    for(int i=0; i<num_linhas; i++){
        if(i!=0){
            teste += (obj_por_linha[i]-obj_por_linha[i-1])/2;
        }
        for(int j=0; j<obj_por_linha[i]; j++){
            jogo->obj[index] = new Balao(2, 1, 540+(j*30)-teste*30, 675-(i*45), 10, 15, 0, 0, 0.9, 0);
            index++;
        }
    }

    //3 bal�es fortes
    for(int i=36; i<=38; i++){
        jogo->obj[i]->troca_tipo(3);
        jogo->obj[i]->troca_cor(0.7, 0.7, 0);
    }

    //2 bal�es com dardo extra
    for(int i=34; i<=40; i+=6){
        jogo->obj[i]->troca_tipo(4);
        jogo->obj[i]->troca_cor(0.8, 0, 0.8);
    }

    //2 bal�es congelantes
    for(int i=70; i<=80; i+=10){
        jogo->obj[i]->troca_tipo(5);
        jogo->obj[i]->troca_cor(0,1,1);
    }

    //2 obst�culos quebr�veis
    jogo->obj[45] = new Obstaculo(1, 1, 540+(3*30)-4*30, 675-(5*45), 10, 15, 0, 0.3, 0.3, 0.3);
    jogo->obj[51] = new Obstaculo(1, 1, 540+(9*30)-4*30, 675-(5*45), 10, 15, 0, 0.3, 0.3, 0.3);
}


int main(void){
   CV::init(&screenWidth, &screenHeight, "T3-smfinkler");
   inicializa_Botoes(&botoes);
   jogo = new Jogo(0, 10);
   inicializa_Objetos_Fase1();
   CV::run();
}
