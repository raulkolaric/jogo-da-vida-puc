//Jogo-da-Vida-CONTROLLER.h - Projeto Jogo da Vida
//28/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Biblioteca padrão
#include <stdio.h>

//Funcoes
void apresentarListas();
void avancar();
int calcularVizinhos(int linha, int coluna);
int existemVivos();
void gerarMortas();
void gerarVivas();
void gravarGeracao();
void incluirExcluir(); 		//Permite incluir ou excluir células vivas manualmente
void jogar();				//Controla o fluxo principal do jogo
void limparGeracao();
void limparMapa();			//Limpa completamente o mapa atual
void limparMatriz();
void limparMatrizAux();
void mostrarEsconder();		//Mostra ou esconde as células vizinhas mortas
void processo();
void proximaGeracao();
void recuperarGeracao();

