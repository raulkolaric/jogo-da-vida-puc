//Jogo-da-Vida-MODEL.cpp - Projeto Jogo da Vida
//04/11/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-MODEL.h"

//Estrutura para representar uma célula
typedef struct cel {
	int lin;
	int col;
	struct cel *next;
} TipoCel;

//Ponteiros para o inicio das listas
TipoCel *pvivo = NULL;
TipoCel *pmorto = NULL;
TipoCel *pvivoprox = NULL;


typedef struct c {
	int lin, col;
} Cel;

typedef struct list {
	int cont; 			//tamanho da lista
	Cel L[MAXLIST];		//maxlist = tamanho maximo das listas (para gravação)
} TipoLista;

TipoLista Lvivo;

struct arquivo {
	TipoLista TL;
} LConfig[MAXINIC];		//maxinic= qtd maxima de configurações iniciais (para gravação)


