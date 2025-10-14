//Jogo-da-Vida-CONTROLLER.cpp - Projeto Jogo da Vida
//14/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-CONTROLLER.h"
#include "JVIDA-KLRR-VIEW.cpp"

void caso1() {
	limparTela();
		
	printf("Digite a dimensao desejada (de 10 a 60): ");
	scanf("%d", &dimensao);
	
	if ((dimensao < 10) || (dimensao > 60)) {
		printf("\n------------DIMENSAO INVALIDA!------------");
		Sleep(500);
		fclear();
	}
	
	else {
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				matriz [linha] [coluna] = '.';
				matrizAuxiliar [linha] [coluna] = '.';
			}
		}
		
		do {
			menu2();
		
			switch(op2) {
				case('1'): 
					seresVivos();
					break;
			
				case('2'):	
					apresentarMapa();
					break;
		
				case('0'):
					limparTela();
					break;
			}
		} while (op2 != '0');
	}
}

void jogar() {
	do {
		menu1();
	
		switch (op1) {
			case('1'): 
				caso1();
				break;
			
			case('2'): 
				regras();
				break;
		
			case('0'):
				break;
		}
	} while (op1 != '0');
}

void seresVivos() {
	do {
		limparTela();
		
		printf("Coordenadas dos Seres Vivos da Geracao: ");
		scanf("%d %d", &coordenadaX, &coordenadaY);
		
		if (((coordenadaX >= 1) && (coordenadaX < dimensao)) && ((coordenadaY >= 1) && (coordenadaY < dimensao))) {
			if (matriz [coordenadaX - 1] [coordenadaY - 1] == '.') {
				matriz [coordenadaX - 1] [coordenadaY - 1] = 'O';
				matrizAuxiliar [coordenadaX - 1] [coordenadaY - 1] = 'O';
				break;
			}
			
			else {
				fclear();
				printf("\nDeseja excluir do mapa (S/N)?: ");
				scanf(" %c", &excluir);
				excluir = toupper(excluir);
				
				if ((excluir != 'S') && (excluir != 'N')) {
					printf("\n--------------OPCAO INVALIDA--------------");
					Sleep(500);
				}
				
				else {
					if (excluir == 'S') {
						matriz [coordenadaX - 1] [coordenadaY - 1] = '.';
						break;
					}
				}	
			}
		}
		
		else {
			printf("\n------------COORDENADAS INVALIDAS!------------");
			Sleep(500);
		}
	} while (1);
}
