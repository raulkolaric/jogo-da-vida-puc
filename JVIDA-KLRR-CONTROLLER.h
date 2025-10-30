//Jogo-da-Vida-CONTROLLER.h - Projeto Jogo da Vida
//28/10/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Biblioteca padr�o
#include <stdio.h>

//Funcoes de manipulacao de listas
void carregaVivo(int ii, int jj);
void carregaMorto(int ii, int jj);
void carregaVivoprox(int ii, int jj);
void mostraLvivo();
void mostraLmorto();
void mostraLvivoprox();
void limpaLvivo();
void limpaLmorto();
void limpaLvivoprox();

void gerarListaVivos();
void gerarListaMortos();
void atualizaMatrizDaLista();

//Funcoes
void apresentarListas();
//void avancar();
int calcularVizinhos(int linha, int coluna);
int existemVivos();
//void gerarMortas();
void gerarVivas();
void gravarGeracao();
void incluirExcluir(); 		//Permite incluir ou excluir c�lulas vivas manualmente
void jogar();				//Controla o fluxo principal do jogo
void limparGeracao();
void limparMapa();			//Limpa completamente o mapa atual
void limparMatriz();
void limparMatrizAux();
void mostrarEsconder();		//Mostra ou esconde as c�lulas vizinhas mortas
void processo();
void proximaGeracao();
void recuperarGeracao();

//dica 7 e 8
void excluiLVivo(int ii, int jj);	//feito	
void carregaMortosVizinhos();			
void carrega1Morto(int ii,int jj);
bool verifica1Morto(int ii,int jj);

















