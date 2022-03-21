#include "Projetil.h"
using namespace std;

//método construtor da classe projétil, executado sempre que um novo projétil é lançado
Projetil::Projetil(float _aceleracao, int mouseX, int mouseY){
    aceleracao = _aceleracao;
    x = 0;
    y = 0;
    x0 = mouseX/4;
    y0 = mouseY/4;
    x2 = x0*(aceleracao*5000);
    y2 = y0;
    x1 = (x2-x0)/2;
    y1 = y0*(aceleracao*5000);
    dx = 0;
    dy = 0;
    vel = 0;
    r = 0;
    g = 0;
    b = 0;
}

//render do projétil, para desenhar na tela
void Projetil::render(){
    vel+= aceleracao+aceleracao;
    x = X_bezier();
    y = Y_bezier();
    dx = dx_X();
    dy = dx_Y();
    CV::line(x, y, (x+(aceleracao*30)*dx), (y+(aceleracao*30)*dy));
    CV::color(8);
    CV::circleFill((x+(aceleracao*30)*dx), (y+(aceleracao*30)*dy), 5, 3);
    CV::color(0);
}

//calcula o valor de X da curva de bezier
float Projetil::X_bezier(){
    return pow(1.0-vel,2)*x0 + 2*(1.0-vel) * vel * x1 + pow(vel,2) * x2;
}

//calcula o valor de Y da curva de bezier
float Projetil::Y_bezier(){
    return pow(1.0-vel,2)*y0 + 2*(1.0-vel) * vel * y1 + pow(vel,2) * y2;
}

//calcula derivada de x para desenhar linha do projétil
float Projetil::dx_X(){
    return (2-2*vel)*(x1-x0)+(2*vel)*(x2-x1);
}

//calcula derivada de y para desenhar linha do projétil
float Projetil::dx_Y(){
    return (2-2*vel)*(y1-y0)+(2*vel)*(y2-y1);
}

//retorna x do projétil
float Projetil::getX(){
    return x;
}

//retorna y do projétil
float Projetil::getY(){
    return y;
}

