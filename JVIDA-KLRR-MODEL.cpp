//JVIDA-6-KLRR-MODEL.cpp - Projeto Jogo da Vida
//11/11/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-MODEL.h"

//Estrutura para representar uma c�lula
typedef struct cel {
	int lin;
	int col;
	struct cel *next;
} TipoCel;

//Ponteiros para o inicio das listas
TipoCel *pvivo = NULL;
TipoCel *pmorto = NULL;
TipoCel *pvivoprox = NULL;

//estrutura de celula para grava��o (nao precisa do next)
typedef struct c {
	int lin, col;
} Cel;

typedef struct list {
	int cont; 			//tamanho da lista
	Cel L[MAXLIST];		//maxlist = tamanho maximo das listas (para grava��o)
} TipoLista;

TipoLista Lvivo;

struct arquivo {
	TipoLista TL;
} LConfig[MAXINIC];		//maxinic= qtd maxima de configura��es iniciais (para grava��o)


