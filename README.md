# Trabalhos_Computacao_Grafica
 
Disciplina: Computação Gráfica<br/>
Professor: César Tadeu Pozzer<br/>
Período: 5º semestre (2021/1)<br/>
<br/>
Este repositório contém os projetos em C (CodeBlocks) desenvolvidas conforme os trabalhos propostos pelo professor.<br/>
<br/>
<br/>
<b>Trabalho 1:</b><br/>
INSTRUÇÕES:<br/>
	  Ao abrir o programa, existe um menu na lateral esquerda disponibilizando as seguintes ações:<br/>
    1 - QUADRADO: Botão que cria um quadrado no meio da tela<br/>
    2 - TRIANGULO: Botão que cria um triângulo no meio da tela<br/>
    3 - CIRCULO: Botão que cria um círculo no meio da tela<br/>
    4 - POLIGONO: Botão para criar um Poligono no meio da tela de acordo com o contador exibido no display logo abaixo<br/>
    5 - + e -: Botões para incrementear e decrementar o contador de lados para criação de polígono do botão POLIGONO<br/>
    6 - ROTACIONAR ESQ: Rotaciona figura selecionada para a esquerda<br/>
    7 - ROTACIONAR DIR: Rotaciona figura selecionada para a direita<br/>
    8 - LARGURA+: Aumenta a largura da figura selecionada<br/>
    9 - LARGURA-: Diminui a largura da figura selecionada<br/>
    10 - ALTURA+: Aumenta a altura da figura selecionada<br/>
    11 - ALTURA-: Diminui a altura da figura selecionada<br/>
    12 - TRAZER PARA TRAS: Traz a figura para trás na tela<br/>
    13 - TRAZER PARA FRENTE: Traz a figura para a frente na tela<br/>
    14 - EXCLUIR: Exclui a figuraa selecionada da tela<br/>
    15 - SALVAR: Salva o desenho atual em um arquivo<br/>
<br/>
    Para selecionar uma figura basta clicar sobre ela<br/>
    Havendo alguma figura selecionada, ao clicar na paleta de cores, essa figura recebe a cor clicada.<br/>
    Havendo alguma figura selecionada é possível movê-la com as setas do teclado e com o mouse (segurando e arrastando)<br/>
    A tecla ESC encerra o programa<br/>
    
    ![image](https://user-images.githubusercontent.com/49410834/159201922-fc1f00fc-51a9-41ff-b15a-e124b518e047.png)
    
<br/>
<br/>
<b>Trabalho 3:</b><br/>
INSTRUÇÕES:<br/>
	  Ao abrir o programa, existe um menu com as seguintes ações:<br/>
    1 - NEW GAME<br/>
    2 - UNLIMITED ARROWS GAME<br/>
    3 - EXIT<br/>
<br/>
    A opção NEW GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com 10 projéteis<br/>
    A opção UNLIMITED ARROWS GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com projéteis infinitos<br/>
    A opção EXIT encerra o jogo<br/>
<br/>
    Os objetos do cenário do jogo são de dois tipo (BALOES e OBSTACULOS)<br/>
    CIRCULOS: BALOES<br/>
    RETANGULOS: OBSTACULOS<br/>
    0- Obstaculo inquebravel (VERMELHO) - Destrói a flecha e é indestrutível<br/>
    1- Obstaculo quebravel (CINZA ESCURO) - Destrói a flecha e é destrutível<br/>
    2- Balao normal (VERDE) - Balão comum que explode ao ser atingido<br/>
    3- Balao forte (AMARELO ESCURO) - Balão que precisa ser atingido 2x para explodir<br/>
    4- Balao com dardo extra (ROXO) - Balão que acrescenta um projétil, explode ao ser atingido<br/>
    5- Balao congelante (CIANO) - Balão indestrutível que congela seus vizinhos (esq e dir) ao ser atingido<br/>
    6- Balao indestrutivel (CIANO) - Balão que não pode ser destruído (o projétil atravessa)<br/>
<br/>
    O objetivo do jogo é eliminar a maior quantidade de balões possível com o número de projéteis dispónível (10 ou infinito)<br/>
    Para lançar um projétil, a força que ele será lançado depende de quanto se segura o mouse (a força aumenta até um máximo e depois diminui até um mínimo)<br/>
    Após iniciar partida, é possível alternar entre as duas fases(cenários) com o botão ESPAÇO, contanto que seja no início da fase(10 projeteis) ou final(0 projéteis)<br/>
    É possível sair da fase e voltar ao MENU a qualquer momento, com a tecla ESC<br/>
    É possível encerrar o jogo com a tecla F4<br/>
    
    ![image](https://user-images.githubusercontent.com/49410834/159201964-f204dd33-3e09-416d-ae24-19db2cf67450.png)
    
<br/>  
<b>Trabalho 4:</b><br/>
INSTRUÇÕES:<br/>
	  Ao abrir o programa, é exibida uma engrenagem, girando nos eixos x, y e z<br/>
<br/>
    O CONTROLE DA ENGRENAGEM É FEITO ATRAVÉS DOS BOTÕES DO TECLADO:<br/>
    1 - Aumenta o número de dentes da engrenagem<br/>
    2 - Diminui o número de dentes da engrenagem<br/>
    3 - Aumenta o raio de dentro da engrenagem (Centro) OBS: Não permite ser maior que o raio de fora<br/>
    4 - Diminui o raio de dentro da engrenagem (Centro)<br/>
    5 - Aumenta o raio de fora da engrenagem<br/>
    6 - Diminui o raio de fora da engrenagem. OBS: Não permite ser menor que o raio de dentro<br/>
    7 - Aumenta a altura dos dentes da engrenagem<br/>
    8 - Diminui a altura dos dentes da engrenagem. OBS: Não pode chegar a 0<br/>
    9 - Aumenta a espessura da engrenagem<br/>
    0 - Diminui a espessura da engrenagem<br/>
    x - Ativa/desativa a rotação em x<br/>
    y - Ativa/desativa a rotação em y<br/>
    z - Ativa/desativa a rotação em z<br/>
    r - Reseta a engrenagem original (que iniciou o programa) e deixa ela parada<br/>
    ESC - Reseta a engrenagem original (que iniciou o programa) girando nos 3 eixos<br/>
    p - Para a rotação em todos os eixos da engrenagem na configuração atual<br/>
<br/>
    OBS: Ao mudar alguma configuração da engrenagem, as rotações são ativadas. Para parar ela novamente, é preciso pausar com a tecla p<br/>
    OBS: Para algumas alterações de configuração, pode não ser muito visível após uma alteração apenas, então pode ser necessário apertar o botão mais vezes<br/>
    OBS: Os pontos foram armazenados em vetores e os índices de matriz calculados de acordo com a fórmula [i*num_coluna+j]<br/>
    É possível encerrar o jogo com a tecla F4<br/>
    
   ![image](https://user-images.githubusercontent.com/49410834/159201834-de0d39d1-834a-4865-aca1-e7439445ac46.png)

