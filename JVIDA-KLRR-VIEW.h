//Jogo-da-Vida-VIEW.h - Projeto Jogo da Vida
//04/11/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Bibliotecas
#include <windows.h>
#include <time.h>

//Variável global usada para armazenar a opção selecionada no menu
char op;

//Funcoes
void apresentarMapa(); 		//Exibe o tabuleiro com as células
void fclear();		   		//Limpa o buffer de entrada do teclado
void limparTela();     		//Limpa a tela do console
char menu();                //Mostra o menu principal e retorna a opção escolhida 
void regras();  			//Mostra as regras do jogo ao usuário
void tempo(int seg);       
