/*********************************************************************
//
//  Descrição:
//	  Arquivo Header contendo a superclasse Figura e suas subclasses (Retangulo, Triangulo, Circulo e Polígono) com suas respectivas funções
//
// *********************************************************************/

#define NUM_PI 3.14159265358979323846
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "gl_canvas2d.h"

using namespace std;

//superclasse Figura
class Figura
{
public:
    int tipo;
    float x, y, largura, altura, rotacao;
    float r, g, b;
    virtual ~Figura() {}
    virtual void render(){}
    virtual bool Colidiu(int mx, int my){}
    virtual void move_figura(int x, int y){}
    virtual void troca_cor(float _r, float _g, float _b){}
    virtual void escreve_arquivo(ofstream& write_fife){}
};

//Retangulo é uma subclasse de Figura
class Retangulo : public Figura {
public:
    Retangulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(int mx, int my);
    virtual void move_figura(int _x, int _y);
    virtual void troca_cor(float _r, float _g, float _b);
    virtual void escreve_arquivo(ofstream& write_fife);
};

//Triangulo é uma subclasse de Figura
class Triangulo : public Figura {
public:
    Triangulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(int mx, int my);
    virtual void move_figura(int _x, int _y);
    virtual void troca_cor(float _r, float _g, float _b);
    virtual void escreve_arquivo(ofstream& write_fife);
};

//Circulo é uma subclasse de Figura
class Circulo : public Figura {
public:
    Circulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(int mx, int my);
    virtual void move_figura(int _x, int _y);
    virtual void troca_cor(float _r, float _g, float _b);
    virtual void escreve_arquivo(ofstream& write_fife);
};

//Poligono é uma subclasse de Figura
class Poligono : public Figura {
public:
    Poligono(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b);
    virtual void render();
    virtual bool Colidiu(int mx, int my);
    virtual void move_figura(int _x, int _y);
    virtual void troca_cor(float _r, float _g, float _b);
    virtual void escreve_arquivo(ofstream& write_fife);
};
