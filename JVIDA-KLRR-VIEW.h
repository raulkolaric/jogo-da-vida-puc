//JVIDA-6-KLRR-VIEW.h - Projeto Jogo da Vida
//11/11/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

//Bibliotecas
#include <windows.h>
#include <time.h>

//Vari�vel global usada para armazenar a op��o selecionada no menu
char op;

//Funcoes
void apresentarMapa(); 		//Exibe o tabuleiro com as c�lulas
void fclear();		   		//Limpa o buffer de entrada do teclado
void limparTela();     		//Limpa a tela do console
char menu();                //Mostra o menu principal e retorna a op��o escolhida 
void regras();  			//Mostra as regras do jogo ao usu�rio
void tempo(int seg);       
