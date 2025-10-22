//Jogo-da-Vida-MODEL.h - Projeto Jogo da Vida
//21/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Variaveis globais
int coordenadaX, coordenadaY;		//Coordenadas da célula a ser manipulada
int dimensao;						//Dimensão do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou célula
int geracao = 1;					//Número da geração atual do jogo
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
char matrizAuxiliar[60][60];		//Matriz auxiliar usada para calcular a próxima geração
int mostrar = 0;					//Flag para mostrar (1) ou esconder (0) vizinhos mortos
