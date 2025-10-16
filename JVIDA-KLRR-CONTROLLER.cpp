//Jogo-da-Vida-CONTROLLER.cpp - Projeto Jogo da Vida
//14/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-CONTROLLER.h"
#include "JVIDA-KLRR-VIEW.cpp"

void apresentarListas() {
	
}

void gravarGeracao() {
	
}

void incluirExcluir() {
	do {
		limparTela();
		printf("-------------------------------------------------------------------");
		printf("\nCoordenadas das Celulas Vivas da Geracao (0 0 para sair): ");
		scanf("%d %d", &coordenadaX, &coordenadaY);
		printf("-------------------------------------------------------------------\n");
		
		if ((coordenadaX == 0) && (coordenadaY == 0)) {
			fclear();
			break;
		}
		
		//Verifica se as coordenadas estão dentro dos limites
		else if (((coordenadaX >= 1) && (coordenadaX <= dimensao)) && ((coordenadaY >= 1) && (coordenadaY <= dimensao))) {
			//Adiciona célula viva se o espaço estiver vazio
			if (matriz [coordenadaX - 1] [coordenadaY - 1] == '.') {
				matriz [coordenadaX - 1] [coordenadaY - 1] = 'O';
				matrizAuxiliar [coordenadaX - 1] [coordenadaY - 1] = 'O';
				printf("\n-------------CELULA ADICIONADA-------------");
				
				apresentarMapa();
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
					
					apresentarMapa();
				}	
			}
		}
		
		else {
			printf("\n------------COORDENADAS INVALIDAS!------------");
		}
		
		Sleep(500);
	} while (1);
}

void jogar() {
	printf("Digite a dimensao desejada (de 10 a 60): ");
	scanf("%d", &dimensao);
	fclear();
	
	//Validação do tamanho do tabuleiro
	if ((dimensao < 10) || (dimensao > 60)) {
		printf("\n------------DIMENSAO INVALIDA!------------");
		Sleep(500);
	}
	
	else {
		//Inicializa as matrizes com células vazias
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				matriz [linha] [coluna] = '.';
				matrizAuxiliar [linha] [coluna] = '.';
			}
		}
	}
	
	//Loop principal do jogo
	do {
		//Exibe o menu inicial
		menu();
	
		switch (op) {
			case('1'): 
				limparMapa();
				break;
				
			case('2'): 
				incluirExcluir();
				break;
			
			case('3'): 
				mostrarEsconder();
				break;
		
			case('4'):
				processo();
				break;
			
			case('5'): 
				apresentarListas();
				break;
			
			case('6'): 
				gravarGeracao();
				break;
				
			case('7'): 
				recuperarGeracao();
				break;
			
			case('8'): 
				limparGeracao();
				break;
		
			case('9'):
				regras();
				break;
				
			case('0'):
				break;
		}
	} while (op != '0');
}

void limparMapa() {
	for (int linha = 0; linha < dimensao; linha++) {
		for (int coluna = 0; coluna < dimensao; coluna++) {
			matriz [linha] [coluna] = '.';
			matrizAuxiliar [linha] [coluna] = '.';
		}
	}
	
	limparTela();
	printf("\n---------------MAPA LIMPO!---------------");
	apresentarMapa();
}

void limparGeracao() {
	
}

void mostrarEsconder() {
	
}

void processo() {
	
}

void recuperarGeracao() {
	
}
