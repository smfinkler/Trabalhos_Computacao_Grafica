
#define NUM_PI 3.14159265
#define DIM 20

#include <math.h>
#include <time.h>

#include "gl_canvas2d.h"

class Ponto{
    public:
    float x, y, z;
};

class Engrenagem{
   Ponto *vetor_Centro_Frente; //vetores da parte da frente da engrenagem
   Ponto *vetor_Centro_Frente_Tr;
   Ponto *vetor_Dentes_Frente;
   Ponto *vetor_Dentes_Frente_Tr;
   Ponto *vetor_Centro_Tras; //vetores da parte de trás da engrenagem
   Ponto *vetor_Centro_Tras_Tr;
   Ponto *vetor_Dentes_Tras;
   Ponto *vetor_Dentes_Tras_Tr;

   float angulo_X = 0;
   float angulo_Y = 0;
   float angulo_Z = 0;

public:
    bool rot_X = true;
    bool rot_Y = true;
    bool rot_Z = true;

    int numero_Dentes;
    float raio_Dentro;
    float raio_Fora;
    float altura_Dente;
    float espessura_Dente;

    Engrenagem(int _numero_Dentes, float _raio_Dentro, float _raio_Fora, float _altura_Dente, float _espessura_Dente){

        float ang;
        numero_Dentes = _numero_Dentes;
        raio_Dentro = _raio_Dentro;
        raio_Fora = _raio_Fora;
        altura_Dente = _altura_Dente;
        espessura_Dente = _espessura_Dente;

        vetor_Centro_Frente = new Ponto[(numero_Dentes+1)*4]; //inicialização vetores de frente
        vetor_Centro_Frente_Tr = new Ponto[(numero_Dentes+1)*4];
        vetor_Dentes_Frente = new Ponto[numero_Dentes*4];
        vetor_Dentes_Frente_Tr = new Ponto[numero_Dentes*4];
        vetor_Centro_Tras = new Ponto[(numero_Dentes+1)*4]; //inicialização vetores de trás
        vetor_Centro_Tras_Tr = new Ponto[(numero_Dentes+1)*4];
        vetor_Dentes_Tras = new Ponto[numero_Dentes*4];
        vetor_Dentes_Tras_Tr = new Ponto[numero_Dentes*4];

        float val = 2.0 * NUM_PI/numero_Dentes/4.0;

        float r0 = raio_Dentro;
        float r1 = raio_Fora - altura_Dente / 2.0;
        float r2 = raio_Fora + altura_Dente / 2.0;

        for (int i = 0; i <= numero_Dentes; i++) {
            ang = i * 2.0 * NUM_PI / numero_Dentes;

            vetor_Centro_Frente[i*4+0].x = r0 * cos(ang);
            vetor_Centro_Frente[i*4+0].y = r0 * sin(ang);
            vetor_Centro_Frente[i*4+0].z = espessura_Dente * 0.5;
            vetor_Centro_Frente[i*4+1].x = r1 * cos(ang);
            vetor_Centro_Frente[i*4+1].y = r1 * sin(ang);
            vetor_Centro_Frente[i*4+1].z = espessura_Dente * 0.5;
            vetor_Centro_Frente[i*4+2].x = r0 * cos(ang);
            vetor_Centro_Frente[i*4+2].y = r0 * sin(ang);
            vetor_Centro_Frente[i*4+2].z = espessura_Dente * 0.5;
            vetor_Centro_Frente[i*4+3].x = r1 * cos(ang + 3 * val);
            vetor_Centro_Frente[i*4+3].y = r1 * sin(ang + 3 * val);
            vetor_Centro_Frente[i*4+3].z = espessura_Dente * 0.5;
        }

        for (int i = 0; i < numero_Dentes; i++) {
            ang = i * 2.0 * NUM_PI / numero_Dentes;

            vetor_Dentes_Frente[i*4+0].x = r1 * cos(ang);
            vetor_Dentes_Frente[i*4+0].y = r1 * sin(ang);
            vetor_Dentes_Frente[i*4+0].z = espessura_Dente * 0.5;
            vetor_Dentes_Frente[i*4+1].x = r2 * cos(ang + val);
            vetor_Dentes_Frente[i*4+1].y = r2 * sin(ang + val);
            vetor_Dentes_Frente[i*4+1].z = espessura_Dente * 0.5;
            vetor_Dentes_Frente[i*4+2].x = r2 * cos(ang + 2 * val);
            vetor_Dentes_Frente[i*4+2].y = r2 * sin(ang + 2 * val);
            vetor_Dentes_Frente[i*4+2].z = espessura_Dente * 0.5;
            vetor_Dentes_Frente[i*4+3].x = r1 * cos(ang + 3 * val);
            vetor_Dentes_Frente[i*4+3].y = r1 * sin(ang + 3 * val);
            vetor_Dentes_Frente[i*4+3].z = espessura_Dente * 0.5;
        }

        for (int i = 0; i <= numero_Dentes; i++) {
            ang = i * 2.0 * NUM_PI / numero_Dentes;

            vetor_Centro_Tras[i*4+0].x = r0 * cos(ang);
            vetor_Centro_Tras[i*4+0].y = r0 * sin(ang);
            vetor_Centro_Tras[i*4+0].z = -espessura_Dente * 0.5;
            vetor_Centro_Tras[i*4+1].x = r1 * cos(ang + 3 * val);
            vetor_Centro_Tras[i*4+1].y = r1 * sin(ang + 3 * val);
            vetor_Centro_Tras[i*4+1].z = -espessura_Dente * 0.5;
            vetor_Centro_Tras[i*4+2].x = r0 * cos(ang);
            vetor_Centro_Tras[i*4+2].y = r0 * sin(ang);
            vetor_Centro_Tras[i*4+2].z = -espessura_Dente * 0.5;
            vetor_Centro_Tras[i*4+3].x = r1 * cos(ang);
            vetor_Centro_Tras[i*4+3].y = r1 * sin(ang);
            vetor_Centro_Tras[i*4+3].z = -espessura_Dente * 0.5;
        }

        val = 2.0 * NUM_PI / numero_Dentes / 4.0;

        for (int i = 0; i < numero_Dentes; i++) {
            ang = i * 2.0 * NUM_PI / numero_Dentes;

            vetor_Dentes_Tras[i*4+0].x = r1 * cos(ang);
            vetor_Dentes_Tras[i*4+0].y = r1 * sin(ang);
            vetor_Dentes_Tras[i*4+0].z = -espessura_Dente * 0.5;
            vetor_Dentes_Tras[i*4+1].x = r2 * cos(ang + val);
            vetor_Dentes_Tras[i*4+1].y = r2 * sin(ang + val);
            vetor_Dentes_Tras[i*4+1].z = -espessura_Dente * 0.5;
            vetor_Dentes_Tras[i*4+2].x = r2 * cos(ang + 2 * val);
            vetor_Dentes_Tras[i*4+2].y = r2 * sin(ang + 2 * val);
            vetor_Dentes_Tras[i*4+2].z = -espessura_Dente * 0.5;
            vetor_Dentes_Tras[i*4+3].x = r1 * cos(ang + 3 * val);
            vetor_Dentes_Tras[i*4+3].y = r1 * sin(ang + 3 * val);
            vetor_Dentes_Tras[i*4+3].z = -espessura_Dente * 0.5;
        }
   }

    //Rotacao de um unico ponto 3D no eixo X
    Ponto rotacionaX(Ponto p ){
        Ponto resp;

        if(rot_X){
            angulo_X += 0.001/numero_Dentes;
        }
        //rotacao em x
        resp.x = cos(angulo_X)*p.x + sin(angulo_X)*p.z;
        resp.z = cos(angulo_X)*p.z - sin(angulo_X)*p.x;
        resp.y = p.y;

        return resp;
    }

    //Rotacao de um unico ponto 3D no eixo Y
    Ponto rotacionaY(Ponto p ){
        Ponto resp;

        if(rot_Y){
            angulo_Y += 0.001/numero_Dentes;
        }
        //rotacao em y
        resp.x = p.x;
        resp.y = cos(angulo_Y)*p.y - sin(angulo_Y)*p.z;
        resp.z = sin(angulo_Y)*p.y + cos(angulo_Y)*p.z;

        return resp;
    }

    //Rotacao de um unico ponto 3D no eixo Z
    Ponto rotacionaZ(Ponto p ){
        Ponto resp;

        if(rot_Z){
            angulo_Z += 0.0005/numero_Dentes;
        }
        //rotacao em z
        resp.x = p.x * cos(angulo_Z) - p.y * sin(angulo_Z);
        resp.y = cos(angulo_Z)*p.y + sin(angulo_Z)*p.x;
        resp.z = p.z;

        return resp;
    }


    //faz a translacao de um unico ponto
    Ponto translada(Ponto p){
        Ponto resp;

        resp.x = p.x;
        resp.y = p.y ;
        resp.z = p.z - 12;

        return resp;
    }

    //projecao em perspectiva, assumindo camera na origem olhando para z negativo.
    Ponto projeta( Ponto p ){
        float d = -10.0;
        Ponto resp;

        resp.x = (p.x*d) / p.z;
        resp.y = (p.y*d) / p.z;
        resp.z = 0;

        return resp;
    }

   //aplica sequencia de transformacoes para fazer a animacao e visualizacao.
    void transforma(){
        Ponto p;

        //Processa cada vertice da engrenagem individualmente.
        for(int x=0; x<=numero_Dentes; x++){
           for(int z=0; z<4; z++){
                //copia os pontos originais
                p = vetor_Centro_Frente[x*4+z];
                //rotacao no eixo x
                p = rotacionaX( p );
                //rotacao no eixo y
                p = rotacionaY( p );
                //rotacao no eixo z
                p = rotacionaZ( p );
                //translacao no eixo z
                p = translada( p );
                //projecao em perspectiva
                vetor_Centro_Frente_Tr[x*4+z] = projeta(p);
            }
        }

        for(int x=0; x<numero_Dentes; x++){
           for(int z=0; z<4; z++){
                //copia os pontos originais
                p = vetor_Dentes_Frente[x*4+z];
                //rotacao no eixo x
                p = rotacionaX( p );
                //rotacao no eixo y
                p = rotacionaY( p );
                //rotacao no eixo z
                p = rotacionaZ( p );
                //translacao no eixo z
                p = translada( p );
                //projecao em perspectiva
                vetor_Dentes_Frente_Tr[x*4+z] = projeta(p);
            }
        }

        //Processa cada vertice da engrenagem individualmente.
        for(int x=0; x<=numero_Dentes; x++){
           for(int z=0; z<4; z++){
                //copia os pontos originais
                p = vetor_Centro_Tras[x*4+z];
                //rotacao no eixo x
                p = rotacionaX( p );
                //rotacao no eixo y
                p = rotacionaY( p );
                //rotacao no eixo z
                p = rotacionaZ( p );
                //translacao no eixo z
                p = translada( p );
                //projecao em perspectiva
                vetor_Centro_Tras_Tr[x*4+z] = projeta(p);
            }
        }

        for(int x=0; x<numero_Dentes; x++){
           for(int z=0; z<4; z++){
                //copia os pontos originais
                p = vetor_Dentes_Tras[x*4+z];
                //rotacao no eixo x
                p = rotacionaX( p );
                //rotacao no eixo y
                p = rotacionaY( p );
                //rotacao no eixo z
                p = rotacionaZ( p );
                //translacao no eixo z
                p = translada( p );
                //projecao em perspectiva
                vetor_Dentes_Tras_Tr[x*4+z] = projeta(p);
            }
        }
    }

    void render(){
        glPointSize(4);

        //a cada renderizacao aplica uma transformacao na engrenagem que faz a rotacao e projecao em perspectiva.
        transforma();

        //desenha os pontos da frente (próximos 2 for)
        for(int x=0; x<=numero_Dentes; x++){
            for(int z=0; z<4; z++){
                CV::point(vetor_Centro_Frente_Tr[x*4+z].x, vetor_Centro_Frente_Tr[x*4+z].y);
            }
        }

        for(int x=0; x<numero_Dentes; x++){
            for(int z=0; z<4; z++){
                CV::point(vetor_Dentes_Frente_Tr[x*4+z].x, vetor_Dentes_Frente_Tr[x*4+z].y);
            }
        }

        //desenha os pontos de trás (próximos 2 for)
        for(int x=0; x<=numero_Dentes; x++){
            for(int z=0; z<4; z++){
                CV::point(vetor_Centro_Tras_Tr[x*4+z].x, vetor_Centro_Tras_Tr[x*4+z].y);
            }
        }

        for(int x=0; x<numero_Dentes; x++){
            for(int z=0; z<4; z++){
                CV::point(vetor_Dentes_Tras_Tr[x*4+z].x, vetor_Dentes_Tras_Tr[x*4+z].y);
            }
        }

        //desenha as arestas dos dentes da frente
        for(int x=0; x<numero_Dentes; x++){
            for(int z=0; z<3; z++){
                CV::line(vetor_Dentes_Frente_Tr[x*4+z].x, vetor_Dentes_Frente_Tr[x*4+z].y, vetor_Dentes_Frente_Tr[x*4+z+1].x, vetor_Dentes_Frente_Tr[x*4+z+1].y);
            }
            if(x!=numero_Dentes-1){
                CV::line(vetor_Dentes_Frente_Tr[x*4+3].x, vetor_Dentes_Frente_Tr[x*4+3].y, vetor_Dentes_Frente_Tr[(x+1)*4].x, vetor_Dentes_Frente_Tr[(x+1)*4].y);
            }
        }
        CV::line(vetor_Dentes_Frente_Tr[(numero_Dentes-1)*4+3].x, vetor_Dentes_Frente_Tr[(numero_Dentes-1)*4+3].y, vetor_Dentes_Frente_Tr[0].x, vetor_Dentes_Frente_Tr[0].y);

        //coloca cor mais escura em algumas arestas da frente
        CV::color(0.5,0,0);

        //desenha as duas arestas do centro para os dentes (frente)
        for(int x=0; x<numero_Dentes; x++){
            CV::line(vetor_Centro_Frente_Tr[x*4].x, vetor_Centro_Frente_Tr[x*4].y, vetor_Centro_Frente_Tr[x*4+3].x, vetor_Centro_Frente_Tr[x*4+3].y);
            if(x==0){
                CV::line(vetor_Centro_Frente_Tr[x*4].x, vetor_Centro_Frente_Tr[x*4].y, vetor_Centro_Frente_Tr[(numero_Dentes-1)*4+1].x, vetor_Centro_Frente_Tr[(numero_Dentes-1)*4+1].y);
            }else{
                CV::line(vetor_Centro_Frente_Tr[x*4].x, vetor_Centro_Frente_Tr[x*4].y, vetor_Centro_Frente_Tr[(x-1)*4+1].x, vetor_Centro_Frente_Tr[(x-1)*4+1].y);
            }
        }

        CV::color(1,0,0);

        //desenha as arestas do centro da frente
        for(int x=0; x<numero_Dentes; x++){
            CV::line(vetor_Centro_Frente_Tr[x*4].x, vetor_Centro_Frente_Tr[x*4].y, vetor_Centro_Frente_Tr[(x+1)*4].x, vetor_Centro_Frente_Tr[(x+1)*4].y);
        }

        //desenha as arestas dos dentes de trás
        for(int x=0; x<numero_Dentes; x++){
            for(int z=0; z<3; z++){
                CV::line(vetor_Dentes_Tras_Tr[x*4+z].x, vetor_Dentes_Tras_Tr[x*4+z].y, vetor_Dentes_Tras_Tr[x*4+z+1].x, vetor_Dentes_Tras_Tr[x*4+z+1].y);
            }
            if(x!=numero_Dentes-1){
                CV::line(vetor_Dentes_Tras_Tr[x*4+3].x, vetor_Dentes_Tras_Tr[x*4+3].y, vetor_Dentes_Tras_Tr[(x+1)*4].x, vetor_Dentes_Tras_Tr[(x+1)*4].y);
            }
        }
        CV::line(vetor_Dentes_Tras_Tr[(numero_Dentes-1)*4+3].x, vetor_Dentes_Tras_Tr[(numero_Dentes-1)*4+3].y, vetor_Dentes_Tras_Tr[0].x, vetor_Dentes_Tras_Tr[0].y);

        //coloca cor mais escura em algumas arestas da frente
        CV::color(0.5,0,0);

        //desenha as duas arestas do centro para os dentes (atrás)
        for(int x=0; x<numero_Dentes; x++){
            CV::line(vetor_Centro_Tras_Tr[x*4].x, vetor_Centro_Tras_Tr[x*4].y, vetor_Centro_Tras_Tr[x*4+1].x, vetor_Centro_Tras_Tr[x*4+1].y);
            if(x==0){
                CV::line(vetor_Centro_Tras_Tr[x*4].x, vetor_Centro_Tras_Tr[x*4].y, vetor_Centro_Tras_Tr[(numero_Dentes-1)*4+3].x, vetor_Centro_Tras_Tr[(numero_Dentes-1)*4+3].y);
            }else{
                CV::line(vetor_Centro_Tras_Tr[x*4].x, vetor_Centro_Tras_Tr[x*4].y, vetor_Centro_Tras_Tr[(x-1)*4+3].x, vetor_Centro_Tras_Tr[(x-1)*4+3].y);
            }
        }

        CV::color(1,0,0);

        //desenha as arestas do centro de trás
        for(int x=0; x<numero_Dentes; x++){
            CV::line(vetor_Centro_Tras_Tr[x*4].x, vetor_Centro_Tras_Tr[x*4].y, vetor_Centro_Tras_Tr[(x+1)*4].x, vetor_Centro_Tras_Tr[(x+1)*4].y);
        }

        //interliga a parte de dentro(núcleo) da face da frente com a face de trás (forma a espessura)
        for(int x=0; x<numero_Dentes; x++){
            for(int z=0; z<3; z++){
                CV::line(vetor_Dentes_Tras_Tr[x*4+z].x, vetor_Dentes_Tras_Tr[x*4+z].y, vetor_Dentes_Frente_Tr[x*4+z].x, vetor_Dentes_Frente_Tr[x*4+z].y);
            }
        }

        //interliga a parte de fora(dentes) da face da frente com a face de trás (forma a espessura)
        for(int x=0; x<numero_Dentes; x++){
            CV::line(vetor_Centro_Tras_Tr[x*4].x, vetor_Centro_Tras_Tr[x*4].y, vetor_Centro_Frente_Tr[x*4].x, vetor_Centro_Frente_Tr[x*4].y);
        }
    }
};
