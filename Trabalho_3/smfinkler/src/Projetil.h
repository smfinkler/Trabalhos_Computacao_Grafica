#ifndef __PROJETIL_H__
#define __PROJETIL_H__

#include <stdio.h>
#include <math.h>
#include "gl_canvas2d.h"
using namespace std;

//classe projetil, com seus atributos e métodos
class Projetil{
public:
    float x,y,dx,dy;
    float forca;
    float x0, y0, x1, y1, x2, y2;
    float r, g, b;
    float vel, aceleracao;
    Projetil(float _aceleracao, int mouseX, int mouseY);
    void render();
    float X_bezier();
    float Y_bezier();
    float dx_X();
    float dx_Y();
    float getX();
    float getY();
};

#endif // __PROJETIL_H__
