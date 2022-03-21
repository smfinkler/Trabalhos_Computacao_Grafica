
#include "jogo.h"
using namespace std;

//método construtor da classe jogo
Jogo::Jogo(int _fase, int _num_projeteis){
    obj = NULL;
    projetil = NULL;
    fase = _fase;
    num_projeteis = _num_projeteis;
    mouse_clicado = false;
    aceleracao=0.001;
    status_aceleracao = true;
}

//render do Jogo, trantando de aspectos importantes do jogo como a colisão com cada tipo de objeto, entre outros.
void Jogo::render(){

    if(fase==0 || fase==1){
        int num_linhas=12;
        int obj_por_linha[num_linhas] = {1,5,7,9,9,11,11,13,13,9,7,3};

        if(fase==1){
            int obj_por_linha2[num_linhas] = {5,7,9,11,11,11,11,11,9,9,9,9};
            for(int i=0; i<num_linhas; i++){
                obj_por_linha[i] = obj_por_linha2[i];
            }
        }

        int indice=0;
        for(int i=0; i<num_linhas; i++){
            for(int j=0; j<obj_por_linha[i]; j++){
                obj[indice]->render();
                if(projetil!=NULL){
                    if(obj[indice]->Colidiu(projetil->getX(), projetil->getY())){
                        int tipo_obj = obj[indice]->get_tipo();
                        if(tipo_obj==2){
                            obj[indice]->troca_status();
                        }else if(tipo_obj==1 && obj[indice]->status==1){
                            obj[indice]->troca_status();
                            projetil = NULL;
                        }else if(tipo_obj==0){
                            projetil = NULL;
                        }else if(tipo_obj==3){
                            obj[indice]->troca_tipo(10);
                            obj[indice]->troca_cor(0, 0.9, 0);
                        }else if(tipo_obj==4 && obj[indice]->get_status()==true){
                            num_projeteis++;
                            obj[indice]->troca_status();
                        }else if(tipo_obj==5){
                            for(int i=indice-1; i<=indice+1; i++){
                                obj[i]->troca_tipo(6);
                                obj[i]->troca_cor(0,1,1);
                            }
                        }
                    }
                }else{
                    if(obj[indice]->get_tipo()==10){
                        obj[indice]->troca_tipo(2);
                    }
                }
                indice++;
            }
        }
    }

    if(mouse_clicado){
        if(aceleracao<0.01 && status_aceleracao==true){
            aceleracao+=0.000005;
        }else if(status_aceleracao==true){
            status_aceleracao=false;
        }else if(aceleracao>0.001 && status_aceleracao==false){
            aceleracao-=0.000005;
        }else{
            status_aceleracao=true;
        }
    }

    CV::color(0,0,0);
    if(projetil!=NULL){
        if(projetil->getX()>1080 || projetil->getY()<0){
            projetil = NULL;
        }else{
            projetil->render();
        }
    }
}

//retorna fase do jogo(0 ou 1)
int Jogo::getFase(){
    return fase;
}

//retorna o número de projeteis disponíveis no momento
int Jogo::getProjeteis(){
    return num_projeteis;
}
