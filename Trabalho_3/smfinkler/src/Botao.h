/*********************************************************************
//
//  Descrição:
//	  Esse arquivo contém a superclasse botao e suas subclasses, para os diferentes botões que possuem suas ações na função action()
//
// *********************************************************************/

#define __BOTAO_H__
#define ALTURA_BOTAO 100
#define LARGURA_BOTAO 300
#define SCREEN_HEIGHT 720
#include <fstream>
#include <list>
#include <string>
#include "gl_canvas2d.h"

using namespace std;
static int botao=0;

//superclasse Botao
class Botao{
public:
    float altura, largura, x, y;
    float r, g, b;
    char label[50];

    virtual ~Botao(){}
    virtual void action(){}
    virtual void on_Click(){}

    void render(){
        CV::color(r, g, b);
        CV::rectFill(x, y, x + largura, y + altura);
        CV::color(0, 0, 0);
        CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro.
    }

    //recebe as coordenadas do mouse para tratar clique ou detectar quando o mouse esta em cima do botao
    bool Colidiu(int mx, int my){
        if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) ){
            return true;
        }
        return false;
    }
};

//subclasse de Botao para iniciar jogo normal
class Botao_Normal_Game : public Botao{
public:
    Botao_Normal_Game(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    virtual void action(){
        botao=1;
    }
};

//subclasse de Botao para iniciar jogo com projéteis infinitos
class Botao_Game_Personalizado : public Botao{
public:
    Botao_Game_Personalizado(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    virtual void action(){
        botao=2;
    }
};

//subclasse de Botao para sair do jogo
class Botao_Exit : public Botao{
public:
    Botao_Exit(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    virtual void action(){
        botao=3;
    }
};

//função de inicialização dos botões, definindo tamanhos e textos e adicionando na lista de botões
void inicializa_Botoes(list<Botao*> *botoes){
    (*botoes).push_back(new Botao_Normal_Game(440, SCREEN_HEIGHT/2+100, LARGURA_BOTAO, ALTURA_BOTAO, "New Game", 0, 0.8, 0));
    (*botoes).push_back(new Botao_Game_Personalizado(440, (SCREEN_HEIGHT/2)-ALTURA_BOTAO+100, LARGURA_BOTAO, ALTURA_BOTAO, "Unlimited Arrows Game", 0, 0.6, 0));
    (*botoes).push_back(new Botao_Exit(440, (SCREEN_HEIGHT/2)-(ALTURA_BOTAO*2)+100, LARGURA_BOTAO, ALTURA_BOTAO, "Exit", 0.8, 0, 0));
}
