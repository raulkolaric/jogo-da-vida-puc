//Jogo-da-Vida-CONTROLLER.cpp - Projeto Jogo da Vida
//21/10/2025 - Grupo: KLRR
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
			if (matriz [coordenadaX - 1] [coordenadaY - 1] != 'O') {
				matriz [coordenadaX - 1] [coordenadaY - 1] = 'O';
				matrizAuxiliar [coordenadaX - 1] [coordenadaY - 1] = 'O';
				printf("\n-------------CELULA ADICIONADA-------------");
				
				apresentarMapa();
			}
			
			else if (matriz [coordenadaX - 1] [coordenadaY - 1] == 'O') {
				// Caso o espaço já esteja ocupado, pergunta se o jogador quer remover
				fclear();
				printf("\nDeseja excluir do mapa? (S/N): ");
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
				char simNao; //Variável para armazenar a resposta do usuário (S ou N)
				
				do {
					limparTela();
					printf("-------------------------------------------------------------------");
					printf("\nDeseja que sejam apresentadas as celulas vizinhas-mortas? (S/N): ");
					scanf(" %c", &simNao);
					fclear();
					simNao = toupper(simNao);
					printf("-------------------------------------------------------------------");
					
					//Verifica a resposta do usuário
					if (simNao == 'S') {
						mostrar = 1;
						break;
					}
					
					else if (simNao == 'N') {
						mostrar = 0;
						break;
					}
					
					else {
						printf("\n\n--------------OPCAO INVALIDA--------------");
					}
					
					Sleep(500);
				} while (1);
				
				apresentarMapa();
				
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
	//Define cada célula da matriz como vazia ('.')
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
	//Se a opção de mostrar células vizinhas-mortas estiver ativada
	if (mostrar == 1) {
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				//Verifica se a célula atual NÃO é viva ('O')
				if (matriz [linha] [coluna] != 'O') {
					int vivos = 0;
					
					//Verifica os 8 vizinhos da célula (varre de -1 a +1 em linha e coluna)
					for (int l = -1; l <= 1; l++) {
						for (int c = -1; c <= 1; c++) {
							int nL = linha + l;
							int nC = coluna + c;
							
							//Garante que não está contando a própria célula e que está dentro dos limites
							if ((l != 0 || c != 0) && nL >= 0 && nL < dimensao && nC >= 0 && nC < dimensao) {
								if (matriz [nL] [nC] == 'O') {
									vivos++;
								}
							}
						}
					}
					
					//Se houver pelo menos uma célula viva vizinha, marca a célula atual com '+'
					if (vivos > 0) {
						matriz [linha] [coluna] = '+';
					}
				}
			}
		}
	}
	
	//Se a opção de mostrar estiver desativada, remove os '+' e volta para '.'
	else {
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				if (matriz [linha] [coluna] == '+') {
					matriz [linha] [coluna] = '.';
				}
			}
		}
	}
}

void processo() {
	
}

void recuperarGeracao() {
	
}
