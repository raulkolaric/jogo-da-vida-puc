//JVIDA-6-KLRR-MODEL.h - Projeto Jogo da Vida
//25/11/2025 - Grupo: KLRR
//Kaua Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include <stdlib.h>

//Variaveis globais
int coordenadaX, coordenadaY;		//Coordenadas da celula a ser manipulada
int dimensao;						//Dimensao do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou celula
int geracao = 1;					//Numero da geracao atual do jogo
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
int mostrar = 0;					//Flag para mostrar (1) ou esconder (0) vizinhos mortos

//Contadores de celulas em cada lista
int totvivo = 0;
int totmorto = 0;
int totvivoprox = 0;

//tamanhos maximo para gravacao
#define MAXLIST 500
#define MAXINIC 50

