/*********************************************************************
//
//  Descrição:
//	  Arquivo contendo implementação das funções das classes Retangulo, Triangulo, Circulo e Polígono.
//
// *********************************************************************/

#include "manager.h"
using namespace std;

    //Funções do retângulo, subclasse da superclasse Figura
    Retangulo::Retangulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    void Retangulo::render(){
        CV::color(r, g, b);
        float _x[4], _y[4], theta, it_pi = NUM_PI/2;
        float _x_aux[4], _y_aux[4];
        theta = 0;

        for (int i = 0; i < 4; i++){
            _x[i] = x + (largura * cos(theta) - largura * sin(theta));
            _y[i] = y + (altura * sin(theta) + altura * cos(theta));
            theta += it_pi;
        }

        for (int i = 0; i < 4; i++){
            float ang = atan2(x - _x[i], y - _y[i]) + rotacao;
            _x[i] = x + (largura * cos(ang) - altura * sin(ang));
            _y[i] = y + (largura * sin(ang) + altura * cos(ang));
        }
        CV::polygonFill(_x, _y,4);
    }

    bool Retangulo::Colidiu(int mx, int my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    void Retangulo::move_figura(int _x, int _y){
        x = _x;
        y = _y;
    }

    void Retangulo::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    void Retangulo::escreve_arquivo(ofstream& write_file){
        write_file.write((char*)&tipo, sizeof(tipo));
        write_file.write((char*)&x, sizeof(x));
        write_file.write((char*)&y, sizeof(y));
        write_file.write((char*)&largura, sizeof(largura));
        write_file.write((char*)&altura, sizeof(altura));
        write_file.write((char*)&rotacao, sizeof(rotacao));
        write_file.write((char*)&r, sizeof(r));
        write_file.write((char*)&g, sizeof(g));
        write_file.write((char*)&b, sizeof(b));
    }

    //Funções do TRIÂNGULO, subclasse da superclasse Figura
    Triangulo::Triangulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    void Triangulo::render(){
        CV::color(r, g, b);
        float _x[3], _y[3], theta, it_pi = 2*NUM_PI/3;
        theta = rotacao;

        _x[0] = x;
        _x[1] = x + largura;
        _x[2] = x - largura;
        _y[0] = y + altura;
        _y[1] = y - altura;
        _y[2] = y - altura;

        for (int i = 0; i < 3; i++){
            float ang = atan2(x - _x[i], y - _y[i]) + rotacao;
            _x[i] = x + (largura * cos(ang) - altura * sin(ang));
            _y[i] = y + (largura * sin(ang) + altura * cos(ang));
        }
        CV::polygonFill(_x, _y,3);
    }

    bool Triangulo::Colidiu(int mx, int my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    void Triangulo::move_figura(int _x, int _y){
        x = _x;
        y = _y;
    }

    void Triangulo::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    void Triangulo::escreve_arquivo(ofstream& write_file){
        write_file.write((char*)&tipo, sizeof(tipo));
        write_file.write((char*)&x, sizeof(x));
        write_file.write((char*)&y, sizeof(y));
        write_file.write((char*)&largura, sizeof(largura));
        write_file.write((char*)&altura, sizeof(altura));
        write_file.write((char*)&rotacao, sizeof(rotacao));
        write_file.write((char*)&r, sizeof(r));
        write_file.write((char*)&g, sizeof(g));
        write_file.write((char*)&b, sizeof(b));
    }

    //Funções do CÍRCULO, subclasse da superclasse Figura
    Circulo::Circulo(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    void Circulo::render(){
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

    bool Circulo::Colidiu(int mx, int my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    void Circulo::move_figura(int _x, int _y){
        x = _x;
        y = _y;
    }

    void Circulo::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    void Circulo::escreve_arquivo(ofstream& write_file){
        write_file.write((char*)&tipo, sizeof(tipo));
        write_file.write((char*)&x, sizeof(x));
        write_file.write((char*)&y, sizeof(y));
        write_file.write((char*)&largura, sizeof(largura));
        write_file.write((char*)&altura, sizeof(altura));
        write_file.write((char*)&rotacao, sizeof(rotacao));
        write_file.write((char*)&r, sizeof(r));
        write_file.write((char*)&g, sizeof(g));
        write_file.write((char*)&b, sizeof(b));
    }

    //Funções do Polígono, subclasse da superclasse Figura
    Poligono::Poligono(int _tipo, float _x, float _y, float _largura, float _altura, float _rotacao, float _r, float _g, float _b){
        tipo = _tipo;
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        rotacao = _rotacao;
        r = _r;
        g = _g;
        b = _b;
    }

    void Poligono::render(){
        CV::color(r, g, b);
        float _x[tipo], _y[tipo], theta, it_pi = 2*NUM_PI/tipo;
        theta = rotacao;

        for (int i = 0; i < tipo; i++){
            _x[i] = x + (largura * cos(theta) - largura * sin(theta));
            _y[i] = y + (altura * sin(theta) + altura * cos(theta));
            theta += it_pi;
        }
        CV::polygonFill(_x, _y, tipo);

    }

    bool Poligono::Colidiu(int mx, int my){
        if( mx >= x - largura && mx <= (x + largura) && my >= y - altura && my <= (y + altura) ){
            return true;
        }
        return false;
    }

    void Poligono::move_figura(int _x, int _y){
        x = _x;
        y = _y;
    }

    void Poligono::troca_cor(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    void Poligono::escreve_arquivo(ofstream& write_file){
        write_file.write((char*)&tipo, sizeof(tipo));
        write_file.write((char*)&x, sizeof(x));
        write_file.write((char*)&y, sizeof(y));
        write_file.write((char*)&largura, sizeof(largura));
        write_file.write((char*)&altura, sizeof(altura));
        write_file.write((char*)&rotacao, sizeof(rotacao));
        write_file.write((char*)&r, sizeof(r));
        write_file.write((char*)&g, sizeof(g));
        write_file.write((char*)&b, sizeof(b));
    }
