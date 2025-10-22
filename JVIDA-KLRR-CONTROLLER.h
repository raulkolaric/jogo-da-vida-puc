//Jogo-da-Vida-CONTROLLER.h - Projeto Jogo da Vida
//21/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Biblioteca padrão
#include <stdio.h>

//Funcoes
void apresentarListas();
int calcularVizinhos(int linha, int coluna);
void gravarGeracao();
void incluirExcluir(); 		//Permite incluir ou excluir células vivas manualmente
void gerarMortas();
void gerarVivas();
void jogar();				//Controla o fluxo principal do jogo
void limparMapa();			//Limpa completamente o mapa atual
void limparMatrizAux();
void limparGeracao();
void mostrarEsconder();		//Mostra ou esconde as células vizinhas mortas
void processo();
void recuperarGeracao();
