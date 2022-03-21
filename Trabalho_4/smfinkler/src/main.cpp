/*********************************************************************
//  INSTRUÇÕES:
//	  Ao abrir o programa, é exibida uma engrenagem, girando nos eixos x, y e z
//
//    O CONTROLE DA ENGRENAGEM É FEITO ATRAVÉS DOS BOTÕES DO TECLADO:
//    1 - Aumenta o número de dentes da engrenagem
//    2 - Diminui o número de dentes da engrenagem
//    3 - Aumenta o raio de dentro da engrenagem (Centro) OBS: Não permite ser maior que o raio de fora
//    4 - Diminui o raio de dentro da engrenagem (Centro)
//    5 - Aumenta o raio de fora da engrenagem
//    6 - Diminui o raio de fora da engrenagem. OBS: Não permite ser menor que o raio de dentro
//    7 - Aumenta a altura dos dentes da engrenagem
//    8 - Diminui a altura dos dentes da engrenagem. OBS: Não pode chegar a 0
//    9 - Aumenta a espessura da engrenagem
//    0 - Diminui a espessura da engrenagem
//    x - Ativa/desativa a rotação em x
//    y - Ativa/desativa a rotação em y
//    z - Ativa/desativa a rotação em z
//    r - Reseta a engrenagem original (que iniciou o programa) e deixa ela parada
//    ESC - Reseta a engrenagem original (que iniciou o programa) girando nos 3 eixos
//    p - Para a rotação em todos os eixos da engrenagem na configuração atual
//
//    OBS: Ao mudar alguma configuração da engrenagem, as rotações são ativadas. Para parar ela novamente, é preciso pausar com a tecla p
//    OBS: Para algumas alterações de configuração, pode não ser muito visível após uma alteração apenas, então pode ser necessário apertar o botão mais vezes
//    OBS: Os pontos foram armazenados em vetores e os índices de matriz calculados de acordo com a fórmula [i*num_coluna+j]
//    OBS: Projeto baseado na demo gl_2_perspectiva
//    É possível encerrar o jogo com a tecla F4
//
// *********************************************************************/

#include "Engrenagem.h"
#include "gl_canvas2d.h"

int opcao = 50;
Engrenagem *s;

////////////////////////////////////////////////////////////////////////////////////////
void render(void){
    CV::color(1,0,0);
    s->render();
    Sleep(10);
}

void keyboard(int key){

    if( key < 200 ){
        opcao = key;
    }

    switch(key){

        //1
        case 49:
            s = new Engrenagem(s->numero_Dentes+1, s->raio_Dentro, s->raio_Fora, s->altura_Dente, s->espessura_Dente);
            break;

        //2
        case 50:
            s = new Engrenagem(s->numero_Dentes-1, s->raio_Dentro, s->raio_Fora, s->altura_Dente, s->espessura_Dente);
            break;

        //3
        case 51:
            if(!(s->raio_Dentro+0.3>s->raio_Fora-0.3)){
                s = new Engrenagem(s->numero_Dentes, s->raio_Dentro+0.3, s->raio_Fora, s->altura_Dente, s->espessura_Dente);
            }
            break;

        //4
        case 52:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro-0.3, s->raio_Fora, s->altura_Dente, s->espessura_Dente);
            break;

        //5
        case 53:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora+0.5, s->altura_Dente, s->espessura_Dente);
            break;

        //6
        case 54:
            if(!(s->raio_Fora-0.5<s->raio_Dentro+0.5)){
                s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora-0.5, s->altura_Dente, s->espessura_Dente);
            }
            break;

        //7
        case 55:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora, s->altura_Dente+0.1, s->espessura_Dente);
            break;

        //8
        case 56:
            if(s->altura_Dente-0.1>0){
                s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora, s->altura_Dente-0.1, s->espessura_Dente);
            }
            break;
        //9
        case 57:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora, s->altura_Dente, s->espessura_Dente+0.2);
            break;

        //0
        case 48:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora, s->altura_Dente, s->espessura_Dente-0.2);
            break;

        //x
        case 120:
            if(s->rot_X){
                s->rot_X = false;
            }else{
                s->rot_X = true;
            }
            break;

        //y
        case 121:
            if(s->rot_Y){
                s->rot_Y = false;
            }else{
                s->rot_Y = true;
            }
            break;

        //z
        case 122:
            if(s->rot_Z){
                s->rot_Z = false;
            }else{
                s->rot_Z = true;
            }
            break;

        //r
        case 114:
            s = new Engrenagem(10, 3.0, 6.0, 1.2, 3.0);
            s->rot_X = false;
            s->rot_Y = false;
            s->rot_Z = false;
            break;

        //p
        case 112:
            s = new Engrenagem(s->numero_Dentes, s->raio_Dentro, s->raio_Fora, s->altura_Dente, s->espessura_Dente);
            s->rot_X = false;
            s->rot_Y = false;
            s->rot_Z = false;
            break;

        //esc volta para o menu
        case 27:
            s = new Engrenagem(10, 3.0, 6.0, 1.2, 3.0);
            break;

        //F4 encerra programa
        case 104:
            exit(0);
            break;
   }
}

void keyboardUp(int key){
    printf("\nLiberou: %d" , key);
}

int main(void){
    int w = 600, h = 600;
    s = new Engrenagem(10, 3.0, 6.0, 1.2, 3.0);
    CV::init(&w, &h, "Engrenagem - Samuel");
    CV::run();
}

