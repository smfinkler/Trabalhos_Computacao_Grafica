Nome: Samuel Matias Finkler

Trabalho 3 de Computação Gráfica

O projeto contém os seguintes arquivos:
	- Main
	- Botao.h com implementação das funções de botão
	- Cenario.h, arquivo header com os métodos da classe Objeto e suas subclasses (Balao e Obstaculo)
	- Cenario.cpp com a implementação das funções descritas no Cenario.h
	- Jogo.h, arquivo header com a classe Jogo e difinição de seus métodos(possui uma render() chamada na render() da main)
	- Jogo.cpp com a implementação das funções descritas no Jogo.h
	- Projetil.h, arquivo header com a classe Projetil e difinição de seus métodos(possui uma render() do projétil, cálculo de Bezier)
	- Projetil.cpp com a implementação das funções descritas no Projetil.h	

INSTRUÇÕES:
    Ao abrir o programa, existe um menu com as seguintes ações:
    1 - NEW GAME
    2 - UNLIMITED ARROWS GAME
    3 - EXIT

    A opção NEW GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com 10 projéteis
    A opção UNLIMITED ARROWS GAME inicia um jogo com 2 fases (Parecidas com fases do jogo real) e com projéteis infinitos
    A opção EXIT encerra o jogo

    Os objetos do cenário do jogo são de dois tipo (BALOES e OBSTACULOS)
    CIRCULOS: BALOES
    RETANGULOS: OBSTACULOS
    0- Obstaculo inquebravel (VERMELHO) - Destrói a flecha e é indestrutível
    1- Obstaculo quebravel (CINZA ESCURO) - Destrói a flecha e é destrutível
    2- Balao normal (VERDE) - Balão comum que explode ao ser atingido
    3- Balao forte (AMARELO ESCURO) - Balão que precisa ser atingido 2x para explodir
    4- Balao com dardo extra (ROXO) - Balão que acrescenta um projétil, explode ao ser atingido
    5- Balao congelante (CIANO) - Balão indestrutível que congela seus vizinhos (esq e dir) ao ser atingido
    6- Balao indestrutivel (CIANO) - Balão que não pode ser destruído (o projétil atravessa)

    O objetivo do jogo é eliminar a maior quantidade de balões possível com o número de projéteis dispónível (10 ou infinito)
    Para lançar um projétil, a força que ele será lançado depende de quanto se segura o mouse (a força aumenta até um máximo e depois diminui até um mínimo, asssim sucessivamente)
    Após iniciar partida, é possível alternar entre as duas fases(cenários) com o botão ESPAÇO, contanto que seja no início da fase(10 projeteis) ou final(0 projéteis)
    É possível sair da fase e voltar ao MENU a qualquer momento, com a tecla ESC
    É possível encerrar o jogo com a tecla F4