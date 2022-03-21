Nome: Samuel Matias Finkler

Trabalho 3 de Computação Gráfica  

O PROJETO CONTÉM OS SEGUINTES ARQUIVOS:
    - Main.cpp
    - Engrenagem.h (Implementação da engrenagem)

INSTRUÇÕES:
    Ao abrir o programa, é exibida uma engrenagem, girando nos eixos x, y e z

O CONTROLE DA ENGRENAGEM É FEITO ATRAVÉS DOS BOTÕES DO TECLADO:
    1 - Aumenta o número de dentes da engrenagem
    2 - Diminui o número de dentes da engrenagem
    3 - Aumenta o raio de dentro da engrenagem (Centro) OBS: Não permite ser maior que o raio de fora
    4 - Diminui o raio de dentro da engrenagem (Centro)
    5 - Aumenta o raio de fora da engrenagem
    6 - Diminui o raio de fora da engrenagem. OBS: Não permite ser menor que o raio de dentro
    7 - Aumenta a altura dos dentes da engrenagem
    8 - Diminui a altura dos dentes da engrenagem. OBS: Não pode chegar a 0
    9 - Aumenta a espessura da engrenagem
    0 - Diminui a espessura da engrenagem
    x - Ativa/desativa a rotação em x
    y - Ativa/desativa a rotação em y
    z - Ativa/desativa a rotação em z
    r - Reseta a engrenagem original (que iniciou o programa) e deixa ela parada
    ESC - Reseta a engrenagem original (que iniciou o programa) girando nos 3 eixos
    p - Para a rotação em todos os eixos da engrenagem na configuração atual

    OBS: Ao mudar alguma configuração da engrenagem, as rotações são ativadas. Para parar ela novamente, é preciso pausar com a tecla p
    OBS: Para algumas alterações de configuração, pode não ser muito visível após uma alteração apenas, então pode ser necessário apertar o botão mais vezes
    OBS: Os pontos foram armazenados em vetores e os índices de matriz calculados de acordo com a fórmula [i*num_coluna+j]
    OBS: Projeto baseado na demo gl_2_perspectiva
    É possível encerrar o jogo com a tecla F4