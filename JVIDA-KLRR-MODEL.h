//Jogo-da-Vida-MODEL.h - Projeto Jogo da Vida
//28/10/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include <stdlib.h>

typedef struct cel {
	int lin;
	int col;
	struct cel *next;
} TipoCel;

//Variaveis globais
int coordenadaX, coordenadaY;		//Coordenadas da c�lula a ser manipulada
int dimensao;						//Dimens�o do tabuleiro (tamanho da matriz)
char excluir;						//Indica se o jogador deseja excluir um ser vivo ou c�lula
int geracao = 1;					//N�mero da gera��o atual do jogo
char matriz[60][60];				//Matriz principal representando o estado atual do jogo
char matrizAuxiliar[60][60];		//Matriz auxiliar usada para calcular a pr�xima gera��o
int mostrar = 0;					//Flag para mostrar (1) ou esconder (0) vizinhos mortos

//Ponteiros para o inicio das listas
TipoCel *pvivo = NULL;
TipoCel *pmorto = NULL;
TipoCel *pvivoprox = NULL;

//Contadores de celulas em cada lista
int totvivo = 0;
int totmorto = 0;
int totvivoprox = 0;

