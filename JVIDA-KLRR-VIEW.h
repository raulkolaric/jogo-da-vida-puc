//JVIDA-6-KLRR-VIEW.h - Projeto Jogo da Vida
//25/11/2025 - Grupo: KLRR
//Kaua Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Bibliotecas
#include <windows.h>
#include <time.h>

//Variavel global usada para armazenar a opcao selecionada no menu
char op;

//Funcoes
void apresentarMapa(); 		//Exibe o tabuleiro com as celulas
void fclear();		   		//Limpa o buffer de entrada do teclado
void limparTela();     		//Limpa a tela do console
char menu();                //Mostra o menu principal e retorna a opcao escolhida 
void regras();  			//Mostra as regras do jogo ao usuario
void tempo(int seg);       
