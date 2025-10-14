//Jogo-da-Vida-VIEW.cpp - Projeto Jogo da Vida
//14/10/2025 - Grupo: KLRR
//Kau� Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-VIEW.h"

void apresentarMapa() {
	limparTela();
	printf("   ");
	
	for (int colunas = 0; colunas < dimensao; colunas++) {
		printf("%d ", colunas + 1);
	}
    
    printf("\n");
    for (int linhas = 0; linhas < dimensao; linhas++) {
    	if (linhas < 9) {
    		printf("%d ", linhas + 1); 
		}
		
		else {
			printf("%d", linhas + 1); 
		}
        for (int i = 0; i < dimensao; i++) {
        	if (i < 10) {
        		printf(" %c", matriz [linhas] [i]);	
			}
			
			else {
				printf("  %c", matriz [linhas] [i]);
			}
        }
        printf("\n");
    }
    
    printf("\n");
    system("pause");
}

//Limpa o buffer de entrada
void fclear() {
	char carac;

	while ((carac = fgetc(stdin)) != EOF && carac != '\n') {
	
	}
}

//Limpa a tela do console
void limparTela() {
	system("cls");
}

//Exibe o menu principal e retorna a op��o escolhida
char menu1() {
	do {
		limparTela();
				
		printf("\n-------------------MENU-------------------\n");
		printf("| 1 - Iniciar jogo                       |\n");
		printf("| 2 - Regras gerais do Jogo              |\n");
		printf("| 0 - Sair do programa                   |\n");
		printf("------------------------------------------\n");
		printf("Opcao selecionada: ");
		scanf("%c", &op1);	
		
		if (op1 >= '0' && op1 <= '2') {
			break;	
		}
			
		printf("\n--------------OPCAO INVALIDA--------------");	
		Sleep(500);
		fclear();
	} while (1);

	fclear();
	return op1; 
}

char menu2() {
	do {
		limparTela();
		
		printf("\n----------------------------------------------------------\n");
		printf("| 1 - Coordenadas dos Seres Vivos                        |\n");
		printf("| 2 - Apresentar Mapa                                    |\n");
		printf("| 0 - Sair (interromper o jogo voltando ao menu inicial) |\n");
		printf("----------------------------------------------------------\n");
		printf("Opcao selecionada: ");
		scanf(" %c", &op2);
		
		if (op1 >= '0' && op1 <= '2') {
			break;	
		}
		
		printf("\n--------------OPCAO INVALIDA--------------");
		Sleep(500);
		fclear();
	} while (1);

	fclear();
	return op2;
}

void regras() {
	limparTela();
	printf("\n---------------------------------------------------Regras resumidas---------------------------------------------------\n");
	printf("\nA ideia base e' que um ser vivo necessita de outros seres vivos para sobreviver e procriar, mas um excesso de densidade"); 
	printf("\npopulacional provoca a morte do ser vivo devido 'a escassez de comida.");
	printf("\nOs individuos vivem num mundo matricial e a geracao seguinte e' gerada a partir da geracao anterior de acordo com as");
	printf("\nseguintes regras:"); 
	printf("\n- Reproducao: Um ser vivo nasce numa celula vazia se essa celula vazia tiver exatamente 3 seres vivos vizinhos.");
	printf("\n- Sobrevivencia: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.");
	printf("\n- Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida.");
	printf("\n- Morte por solidao: Um ser vivo com 0 ou apenas 1 vizinho morre de solidao.");
	printf("\nA cada geracao, as regras devem ser aplicadas para todos os seres vivos ao mesmo tempo (isto e no mesmo passo) para"); 
	printf("\nobtermos o proximo passo ou geracao.\n\n");
	system("pause");
}
