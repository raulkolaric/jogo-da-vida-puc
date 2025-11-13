//JVIDA-6-KLRR-MODEL.h - Projeto Jogo da Vida
//11/11/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include <stdlib.h>

//Variaveis globais
int coordenadaX, coordenadaY;		//Coordenadas da c�lula a ser manipulada
int dimensao;						//Dimens�o do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou c�lula
int geracao = 1;					//N�mero da gera��o atual do jogo
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
int mostrar = 0;					//Flag para mostrar (1) ou esconder (0) vizinhos mortos

//Contadores de celulas em cada lista
int totvivo = 0;
int totmorto = 0;
int totvivoprox = 0;

//tamanhos maximo para grava��o
#define MAXLIST 500
#define MAXINIC 50

