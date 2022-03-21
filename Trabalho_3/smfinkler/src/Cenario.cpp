
#include "cenario.h"
using namespace std;

    //método construtor do balão
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

    //render do balão, para desenhar os balões "vivos" na tela
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

    //teste de colisão com o balão
    bool Balao::Colidiu(float mx, float my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) && status==true){
            return true;
        }
        return false;
    }

    //função para alterar tipo do balão
    void Balao::troca_tipo(int _tipo){
        tipo = _tipo;
    }

    //função para trocar status do balão (ativo/inativo)
    void Balao::troca_status(){
        if(status){
            status=false;
        }else{
            status=true;
        }
    }

    //função para pegar o status do balão
    int Balao::get_status(){
        return status;
    }

    //função para pegar o tipo do balão
    int Balao::get_tipo(){
        return tipo;
    }

    //função para trocar cor do balão
    void Balao::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    //método construtor do obstáculo
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

    //render do obstáculo, para desenhar os obstáculos "vivos" na tela
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

    //teste de colisão com o obstáculo
    bool Obstaculo::Colidiu(float mx, float my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    //função para pegar o tipo do obstáculo(destrutível/indestrutível)
    int Obstaculo::get_tipo(){
        return tipo;
    }

    //função para trocar status do obstáculo
    void Obstaculo::troca_status(){
        if(status){
            status=false;
        }else{
            status=true;
        }
    }

    //função para trocar cor do obstáculo
    void Obstaculo::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }
