//Jogo-da-Vida-CONTROLLER.h - Projeto Jogo da Vida
//04/11/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Biblioteca padrão
#include <stdio.h>

//Funcoes
void apresentarListas();
void atualizarMatrizDaLista();
int calcularVizinhos(int linha, int coluna);
void carregarMorto(int linha, int coluna);
void carregarVivo(int linha, int coluna);
void carregarVivoprox(int linha, int coluna);
void excluirLVivo(int linha, int coluna);
void excluirLMorto(int linha, int coluna);
int existemVivos();
void gerarVivas();
void gerarListaMortos();
void gerarListaVivos();
void gravarGeracao();
void incluirExcluir(); 		//Permite incluir ou excluir células vivas manualmente
void jogar();				//Controla o fluxo principal do jogo
void limparGeracao();
void limparLmorto();
void limparLvivo();
void limparLvivoprox();
void limparMapa();			//Limpa completamente o mapa atual
void limparMatriz();
void mostrarEsconder();		//Mostra ou esconde as células vizinhas mortas
void mostrarLmorto();
void mostrarLvivo();
void mostrarLvivoprox();
void processo();
void proximaGeracao();
void recuperarGeracao();

//void carregarMortosVizinhos();			
//void carregar1Morto(int ii,int jj);
//bool verificar1Morto(int ii,int jj);

//etapa 5
void gravarGeracao();
void recuperarGeracao();


















