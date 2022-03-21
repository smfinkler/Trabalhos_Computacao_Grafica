/*********************************************************************
//
//  Descrição:
//	  Esse arquivo contém a superclasse botao e suas subclasses, para os diferentes botões que possuem suas ações na função action()
//
// *********************************************************************/

#define __BOTAO_H__
#define ALTURA_PALETA 40
#define ALTURA_BOTAO 32
#define LARGURA_BOTAO 200
#define SCREEN_HEIGHT 720
#define TAM_FIGURA 50
#include <fstream>
#include <list>
#include <string>
#include "gl_canvas2d.h"

using namespace std;

int lados_poligono = 4; //variável global contador do lado de poligonos do display

//superclasse Botao
class Botao{
public:
    float altura, largura, x, y;
    float r, g, b;
    char label[50];

    virtual ~Botao(){}
    virtual void action(){}
    virtual void action(list<Figura*> *figuras, Figura *fig){}
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

//subclasse de Botao para os botões da paleta de cores
class Botao_Cor : public Botao{
public:
    Botao_Cor(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
        if(fig != nullptr)
            fig->troca_cor(r, g, b);
    }
};

//subclasse de Botao para os botões de adicionar figuras
class Botao_Add_Figure : public Botao{
public:
    int tipo;
    Botao_Add_Figure(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b, int _tipo){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        tipo = _tipo;
        strcpy(label, _label);
    }

    void action(list<Figura*> *figuras, Figura *fig){
        switch(tipo){
            case 1:
                (*figuras).insert((*figuras).end(), new Retangulo(tipo, 640, SCREEN_HEIGHT/2, TAM_FIGURA, TAM_FIGURA, 0,0,0,0.8));
                break;
            case 2:
                (*figuras).insert((*figuras).end(), new Triangulo(tipo, 640, SCREEN_HEIGHT/2, TAM_FIGURA, TAM_FIGURA, 0,0,0.6,0));
                break;
            case 3:
                (*figuras).insert((*figuras).end(), new Circulo(tipo, 640, SCREEN_HEIGHT/2, TAM_FIGURA, TAM_FIGURA, 0.8,0,0.8,0));
                break;
            default:
                (*figuras).insert((*figuras).end(), new Poligono(lados_poligono, 640, SCREEN_HEIGHT/2, TAM_FIGURA, TAM_FIGURA, 0,0.8,0,0));
        }
    }
};

//subclasse de Botao para os botões de rotacionar figura
class Botao_Rotacionar : public Botao{
public:
    int tipo;
    Botao_Rotacionar(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b, int _tipo){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        tipo = _tipo;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
        if(fig != nullptr){
            if(tipo==1){
                fig->rotacao += PI/18;
            }else{
                fig->rotacao -= PI/18;
            }
        }
    }
};

//subclasse de Botao para para os botões de redimensionar figuras
class Botao_Redimensionar : public Botao{
public:
    int tipo;
    Botao_Redimensionar(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b, int _tipo){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        tipo = _tipo;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
        if(fig != nullptr){
            switch(tipo){
                case 1:
                    fig->largura+=5;
                    break;
                case 2:
                    if((fig->largura)>5){
                        fig->largura-=5;
                    }
                    break;
                case 3:
                    fig->altura+=5;
                    break;
                case 4:
                    if((fig->altura)>5){
                        fig->altura-=5;
                    }
                    break;
            }
        }
    }
};

//subclasse de Botao para os botões de mandar figura para frente e para trás
class Botao_ParaFrenteTras : public Botao{
public:
    int tipo;
    Botao_ParaFrenteTras(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b, int _tipo){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        tipo = _tipo;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
        if(fig != nullptr){
            if(tipo==1){ //manda para trás
                (*figuras).remove(fig);
                (*figuras).insert((*figuras).begin(),fig);
                cout << "d";
            }else{ //manda para frente
                (*figuras).remove(fig);
                (*figuras).insert((*figuras).end(),fig);
                cout << "d";
            }
        }
    }
};

//subclasse de Botao para o botão de excluir figura selecionada
class Botao_Excluir : public Botao{
public:
    Botao_Excluir(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    void action(list<Figura*> *figuras, Figura *fig){
        if(fig != nullptr)
            (*figuras).remove(fig);
    }
};

//subclasse de Botao para o botão de salvar conteúdo em arquivo binário
class Botao_Salvar : public Botao{
public:
    Botao_Salvar(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
    ofstream write_file("smfinkler/figuras.gr", ios::out|ios::binary);
        for(auto it : (*figuras)){
            it->escreve_arquivo(write_file);
        }
    }
};

//subclasse de Botao para os botões de incrementar/decrementar o contador de lados para polígono
class Botao_MaisMenos : public Botao{
public:
    int tipo;
    Botao_MaisMenos(float _x, float _y, float _largura, float _altura, char *_label, float _r, float _g, float _b, int _tipo){
        x = _x;
        y = _y;
        largura = _largura;
        altura  = _altura;
        r = _r;
        g = _g;
        b = _b;
        tipo = _tipo;
        strcpy(label, _label);
    }

    virtual void action(list<Figura*> *figuras, Figura *fig){
        if(tipo==1){
            lados_poligono++;
        }else if(lados_poligono>=5){
            lados_poligono--;
        }
    }
};

//função de inicialização dos botões, definindo tamanhos e textos e adicionando na lista de botões
void inicializa_Botoes(list<Botao*> *botoes){
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*0, SCREEN_HEIGHT-ALTURA_PALETA*1, ALTURA_PALETA, ALTURA_PALETA, "", 0, 1, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*1, SCREEN_HEIGHT-ALTURA_PALETA*1, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0.8, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*2, SCREEN_HEIGHT-ALTURA_PALETA*1, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0.6, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*3, SCREEN_HEIGHT-ALTURA_PALETA*1, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0.4, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*4, SCREEN_HEIGHT-ALTURA_PALETA*1, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0.2, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*0, SCREEN_HEIGHT-ALTURA_PALETA*2, ALTURA_PALETA, ALTURA_PALETA, "", 0, 1, 1));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*1, SCREEN_HEIGHT-ALTURA_PALETA*2, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0, 1));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*2, SCREEN_HEIGHT-ALTURA_PALETA*2, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0, 0.8));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*3, SCREEN_HEIGHT-ALTURA_PALETA*2, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0, 0.6));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*4, SCREEN_HEIGHT-ALTURA_PALETA*2, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0, 0.4));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*0, SCREEN_HEIGHT-ALTURA_PALETA*3, ALTURA_PALETA, ALTURA_PALETA, "", 1, 0.5, 0.5));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*1, SCREEN_HEIGHT-ALTURA_PALETA*3, ALTURA_PALETA, ALTURA_PALETA, "", 1, 0, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*2, SCREEN_HEIGHT-ALTURA_PALETA*3, ALTURA_PALETA, ALTURA_PALETA, "", 0.8, 0, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*3, SCREEN_HEIGHT-ALTURA_PALETA*3, ALTURA_PALETA, ALTURA_PALETA, "", 0.6, 0, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*4, SCREEN_HEIGHT-ALTURA_PALETA*3, ALTURA_PALETA, ALTURA_PALETA, "", 0.4, 0, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*0, SCREEN_HEIGHT-ALTURA_PALETA*4, ALTURA_PALETA, ALTURA_PALETA, "", 1, 1, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*1, SCREEN_HEIGHT-ALTURA_PALETA*4, ALTURA_PALETA, ALTURA_PALETA, "", 1, 0.5, 0));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*2, SCREEN_HEIGHT-ALTURA_PALETA*4, ALTURA_PALETA, ALTURA_PALETA, "", 1, 0, 1));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*3, SCREEN_HEIGHT-ALTURA_PALETA*4, ALTURA_PALETA, ALTURA_PALETA, "", 0.8, 0, 0.8));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*4, SCREEN_HEIGHT-ALTURA_PALETA*4, ALTURA_PALETA, ALTURA_PALETA, "", 0.5, 0, 0.5));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*0, SCREEN_HEIGHT-ALTURA_PALETA*5, ALTURA_PALETA, ALTURA_PALETA, "", 0.8, 0.8, 0.8));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*1, SCREEN_HEIGHT-ALTURA_PALETA*5, ALTURA_PALETA, ALTURA_PALETA, "", 0.6, 0.6, 0.6));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*2, SCREEN_HEIGHT-ALTURA_PALETA*5, ALTURA_PALETA, ALTURA_PALETA, "", 0.4, 0.4, 0.4));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*3, SCREEN_HEIGHT-ALTURA_PALETA*5, ALTURA_PALETA, ALTURA_PALETA, "", 0.2, 0.2, 0.2));
    (*botoes).push_back(new Botao_Cor(ALTURA_PALETA*4, SCREEN_HEIGHT-ALTURA_PALETA*5, ALTURA_PALETA, ALTURA_PALETA, "", 0, 0, 0));
    (*botoes).push_back(new Botao_Add_Figure(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*1)-1, LARGURA_BOTAO, ALTURA_BOTAO, "Quadrado", 0.5, 0.75, 0.5, 1));
    (*botoes).push_back(new Botao_Add_Figure(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*2)-2, LARGURA_BOTAO, ALTURA_BOTAO, "Triangulo", 0.5, 0.75, 0.5, 2));
    (*botoes).push_back(new Botao_Add_Figure(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*3)-3, LARGURA_BOTAO, ALTURA_BOTAO, "Circulo", 0.5, 0.75, 0.5, 3));
    (*botoes).push_back(new Botao_Add_Figure(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*4)-4, LARGURA_BOTAO, ALTURA_BOTAO, "Poligono", 0.5, 0.75, 0.5, 4));
    (*botoes).push_back(new Botao_MaisMenos(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*5)-5, ALTURA_BOTAO, ALTURA_BOTAO, "+", 0, 0.7, 0, 1));
    (*botoes).push_back(new Botao_MaisMenos(ALTURA_BOTAO+1, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*5)-5, ALTURA_BOTAO, ALTURA_BOTAO, "-", 1, 0.1, 0.1, 2));
    (*botoes).push_back(new Botao_Rotacionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*6)-6, LARGURA_BOTAO, ALTURA_BOTAO, "Rotacionar Esq.", 0.5, 0.5, 0.75,1));
    (*botoes).push_back(new Botao_Rotacionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*7)-7, LARGURA_BOTAO, ALTURA_BOTAO, "Rotacionar Dir.", 0.5, 0.5, 0.75,2));
    (*botoes).push_back(new Botao_Redimensionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*8)-8, LARGURA_BOTAO, ALTURA_BOTAO, "Largura+", 0.5, 0.5, 0.75, 1));
    (*botoes).push_back(new Botao_Redimensionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*9)-9, LARGURA_BOTAO, ALTURA_BOTAO, "Largura-", 0.5, 0.5, 0.75, 2));
    (*botoes).push_back(new Botao_Redimensionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*10)-10, LARGURA_BOTAO, ALTURA_BOTAO, "Altura+", 0.5, 0.5, 0.75, 3));
    (*botoes).push_back(new Botao_Redimensionar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*11)-11, LARGURA_BOTAO, ALTURA_BOTAO, "Altura-", 0.5, 0.5, 0.75, 4));
    (*botoes).push_back(new Botao_ParaFrenteTras(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*12)-12, LARGURA_BOTAO, ALTURA_BOTAO, "Trazer para Tras", 0.75, 0.5, 0.5, 1));
    (*botoes).push_back(new Botao_ParaFrenteTras(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*13)-13, LARGURA_BOTAO, ALTURA_BOTAO, "Trazer para Frente", 0.75, 0.5, 0.5, 2));
    (*botoes).push_back(new Botao_Excluir(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*14)-14, LARGURA_BOTAO, ALTURA_BOTAO, "Excluir", 1, 0.1, 0.1));
    (*botoes).push_back(new Botao_Salvar(0, SCREEN_HEIGHT-(ALTURA_PALETA*5+ALTURA_BOTAO*15)-15, LARGURA_BOTAO, ALTURA_BOTAO, "Salvar", 0, 0.7, 0));
}
