//JVIDA-6-KLRR-CONTROLLER.h - Projeto Jogo da Vida
//11/11/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Biblioteca padr�o
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
void incluirExcluir(); 		//Permite incluir ou excluir c�lulas vivas manualmente
void jogar();				//Controla o fluxo principal do jogo
void limparGeracao();
void limparLmorto();
void limparLvivo();
void limparLvivoprox();
void limparMapa();			//Limpa completamente o mapa atual
void limparMatriz();
void mostrarEsconder();		//Mostra ou esconde as c�lulas vizinhas mortas
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


















