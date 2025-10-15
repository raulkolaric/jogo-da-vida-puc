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
	
	//Validação do tamanho do tabuleiro
	if ((dimensao < 10) || (dimensao > 60)) {
		printf("\n------------DIMENSAO INVALIDA!------------");
		Sleep(500);
		fclear();
	}
	
	else {
		//Inicializa as matrizes com células vazias
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				matriz [linha] [coluna] = '.';
				matrizAuxiliar [linha] [coluna] = '.';
			}
		}
		
		//Menu secundário para manipulação do tabuleiro
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
	//Loop principal do jogo
	do {
		//Exibe o menu inicial
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
		
		printf("Coordenadas dos Seres Vivos da Geracao (0 0 para sair): ");
		scanf("%d %d", &coordenadaX, &coordenadaY);
		
		if ((coordenadaX == 0) && (coordenadaY == 0)) {
			break;
		}
		
		//Verifica se as coordenadas estão dentro dos limites
		else if (((coordenadaX >= 1) && (coordenadaX <= dimensao)) && ((coordenadaY >= 1) && (coordenadaY <= dimensao))) {
			//Adiciona célula viva se o espaço estiver vazio
			if (matriz [coordenadaX - 1] [coordenadaY - 1] == '.') {
				matriz [coordenadaX - 1] [coordenadaY - 1] = 'O';
				matrizAuxiliar [coordenadaX - 1] [coordenadaY - 1] = 'O';
				printf("\n-------------CELULA ADICIONADA-------------");
			}
			
			else {
				// Caso o espaço já esteja ocupado, pergunta se o jogador quer remover
				fclear();
				printf("\nDeseja excluir do mapa (S/N)?: ");
				scanf(" %c", &excluir);
				excluir = toupper(excluir);
				
				if ((excluir != 'S') && (excluir != 'N')) {
					printf("\n--------------OPCAO INVALIDA--------------");
				}
				
				else {
					if (excluir == 'S') {
						matriz [coordenadaX - 1] [coordenadaY - 1] = '.';
						printf("\n-------------REMOCAO CONCLUIDA-------------");
					}
					
					else {
						printf("\n-----------REMOCAO NAO REALIZADA-----------");
					}
				}	
			}
		}
		
		else {
			printf("\n------------COORDENADAS INVALIDAS!------------");
		}
		
		Sleep(500);
	} while (1);
}
