
#include "cenario.h"
using namespace std;

    //m�todo construtor do bal�o
    Balao::Balao(int _tipo, int _status, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        status = _status;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    //render do bal�o, para desenhar os bal�es "vivos" na tela
    void Balao::render(){
        if(status!=0){
            CV::color(r, g, b);
            float _x[30], _y[30], theta, it_pi = 2*NUM_PI/30;
            theta = rotacao;

            for (int i = 0; i < 30; i++){
                _x[i] = x + (largura * cos(theta) - largura * sin(theta));
                _y[i] = y + (altura * sin(theta) + altura * cos(theta));
                theta += it_pi;
            }
            CV::polygonFill(_x, _y,30);
        }
    }

    //teste de colis�o com o bal�o
    bool Balao::Colidiu(float mx, float my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) && status==true){
            return true;
        }
        return false;
    }

    //fun��o para alterar tipo do bal�o
    void Balao::troca_tipo(int _tipo){
        tipo = _tipo;
    }

    //fun��o para trocar status do bal�o (ativo/inativo)
    void Balao::troca_status(){
        if(status){
            status=false;
        }else{
            status=true;
        }
    }

    //fun��o para pegar o status do bal�o
    int Balao::get_status(){
        return status;
    }

    //fun��o para pegar o tipo do bal�o
    int Balao::get_tipo(){
        return tipo;
    }

    //fun��o para trocar cor do bal�o
    void Balao::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    //m�todo construtor do obst�culo
    Obstaculo::Obstaculo(int _tipo, int _status, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        status = _status;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    //render do obst�culo, para desenhar os obst�culos "vivos" na tela
    void Obstaculo::render(){
        if(status!=0){
           CV::color(r, g, b);
            float _x[4], _y[4], theta, it_pi = 2*NUM_PI/4;
            theta = rotacao;

            for (int i = 0; i < 4; i++){
                _x[i] = x + (largura * cos(theta) - largura * sin(theta));
                _y[i] = y + (altura * sin(theta) + altura * cos(theta));
                theta += it_pi;
            }
            CV::polygonFill(_x, _y, 4);
        }
    }

    //teste de colis�o com o obst�culo
    bool Obstaculo::Colidiu(float mx, float my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    //fun��o para pegar o tipo do obst�culo(destrut�vel/indestrut�vel)
    int Obstaculo::get_tipo(){
        return tipo;
    }

    //fun��o para trocar status do obst�culo
    void Obstaculo::troca_status(){
        if(status){
            status=false;
        }else{
            status=true;
        }
    }

    //fun��o para trocar cor do obst�culo
    void Obstaculo::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }
