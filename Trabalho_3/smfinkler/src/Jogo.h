
#ifndef __JOGO_H__
#define __JOGO_H__

#include <stdio.h>
#include "cenario.h"
#include "projetil.h"
#include "gl_canvas2d.h"
using namespace std;

//classe Jogo com atributos importantes para o funcionamento, como os objetos do cenário, projétil, entre outros...
class Jogo{
public:
    Objeto **obj;
    Projetil* projetil;
    int fase;
    int num_projeteis;
    bool mouse_clicado;
    float aceleracao;
    bool status_aceleracao;

    Jogo(int _fase, int _num_projeteis);
    int getFase();
    int getProjeteis();
    void render();
};

#endif // __PROJETIL_H__
