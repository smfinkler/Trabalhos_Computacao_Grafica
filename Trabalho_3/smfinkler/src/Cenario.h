#define NUM_PI 3.14159265358979323846
#include <stdio.h>
#include <stdbool.h>
#include <cmath>
#include "gl_canvas2d.h"

using namespace std;

//superclasse Botao
class Objeto{
public:
    int tipo;
    int status;
    float x, y, largura, altura, rotacao, r, g, b;
    virtual ~Objeto() {}
    virtual void render(){}
    virtual bool Colidiu(float mx, float my){}
    virtual void troca_tipo(int _tipo){}
    virtual void troca_status(){}
    virtual int get_status(){}
    virtual int get_tipo(){}
    virtual void troca_cor(float _r, float _g, float _b){}
};

////subclasse de Objeto
class Balao : public Objeto {
public:
    Balao(int _tipo, int _status, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(float mx, float my);
    virtual void troca_tipo(int _tipo);
    virtual void troca_status();
    virtual int get_status();
    virtual int get_tipo();
    virtual void troca_cor(float _r, float _g, float _b);
};

////subclasse de Objeto
class Obstaculo : public Objeto {
public:
    Obstaculo(int _tipo, int _status, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(float mx, float my);
    virtual int get_tipo();
    virtual void troca_status();
    virtual void troca_cor(float _r, float _g, float _b);
};
