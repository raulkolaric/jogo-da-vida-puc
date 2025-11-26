//JVIDA-6-KLRR-MODEL.cpp - Projeto Jogo da Vida
//25/11/2025 - Grupo: KLRR
//Kaua Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-MODEL.h"

//Estrutura para representar uma celula
typedef struct cel {
	int lin;
	int col;
	struct cel *next;
} TipoCel;

//Ponteiros para o inicio das listas
TipoCel *pvivo = NULL;
TipoCel *pmorto = NULL;
TipoCel *pvivoprox = NULL;

//Estrutura de celula para gravacao (nao precisa do next)
typedef struct c {
	int lin, col;
} Cel;

typedef struct list {
	int cont; 			//tamanho da lista
	Cel L[MAXLIST];		//maxlist = tamanho maximo das listas (para gravacao)
} TipoLista;

TipoLista Lvivo;

struct arquivo {
	TipoLista TL;
} LConfig[MAXINIC];		//maxinic = qtd maxima de configuracoes iniciais (para gravacao)


