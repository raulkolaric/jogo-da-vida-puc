//Jogo-da-Vida-CONTROLLER.cpp - Projeto Jogo da Vida
//28/10/2025 - Grupo: KLRR
//Kauã Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-CONTROLLER.h"
#include "JVIDA-KLRR-VIEW.cpp"

void apresentarListas() {
	
}

/*void avancar() {
	//flag
	int flag = 0;
	printf("Avancar manual ou automaticamente?\n[0] Manual\n[1] Automatico\n");
	scanf("%d", &flag);
	
	//manual 0
	if (flag == 0) {
		
	}
	//automatico 1
	if (flag == 1){
		
	}
}*/


int calcularVizinhos(int linha, int coluna) {
	int qtd = 0;
	
	//3 superiores
	if (linha - 1 >= 0 && coluna - 1 >= 0) {
		if (matriz [linha - 1] [coluna - 1] == 'O') {
			qtd++;
		}
	}
	
	if (linha - 1 >= 0 && coluna >= 0) {
		if (matriz [linha - 1] [coluna] == 'O') {
			qtd++;
		}
	}
	
	if (linha - 1 >= 0 && coluna + 1 < dimensao) {
		if (matriz [linha - 1] [coluna + 1] == 'O') {
			qtd++;
		}
	}
		
	//2 laterais
	if (linha >= 0 && coluna - 1 >= 0) {
		if (matriz [linha] [coluna - 1] == 'O') {
			qtd++;
		}
	}
	
	if (linha >= 0 && coluna + 1 < dimensao) {
		if (matriz [linha] [coluna + 1] == 'O') {
			qtd++;
		}
	}
		
	//3 inferiores
	if (linha + 1 < dimensao && coluna - 1 >= 0) {
		if (matriz [linha + 1] [coluna - 1] == 'O') {
			qtd++;
		}
	}
	
	if (linha + 1 < dimensao && coluna >= 0) {
		if (matriz [linha + 1] [coluna] == 'O') {
			qtd++;
		}
	}
	
	if (linha + 1 < dimensao && coluna + 1 < dimensao) {
		if (matriz [linha + 1] [coluna + 1] == 'O') {
			qtd++;
		}
	}
	
	return qtd;
}

int existemVivos() {
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            if (matriz [i] [j] == 'O') {
                return 1; 
            }
        }
    }
    
    return 0; 
}

//void gerarMortas() {
//	for (int i = 0; i < dimensao; i++) {
//		for (int j = 0; j < dimensao; j++) {
//			int qtd = calcularVizinhos(i, j);
//			
//			if (qtd <= 1) {
//				matrizAuxiliar[i][j] = '.';
//			}
//			if (qtd >= 4) {
//				matrizAuxiliar[i][j] = '.';
//			}
//		}
//	}
//}

void gerarVivas() {
	for (int i = 0; i < dimensao; i++) {
		for (int j = 0; j < dimensao; j++) {
			int qtd = calcularVizinhos(i, j);
			
			if (matriz [i] [j] == 'O') {
				if (qtd == 2 || qtd == 3) {
					matrizAuxiliar [i] [j] = 'O';
				}
			}
			else {
				if (qtd == 3) {
					matrizAuxiliar [i] [j] = 'O';
				}
			}
		}
	}
}

void gravarGeracao() {
	
}

void incluirExcluir() {
	do {
		apresentarMapa();
		
		printf("\n-------------------------------------------------------------------");
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
			}
			
			else if (matriz [coordenadaX - 1] [coordenadaY - 1] == 'O') {
				//Caso o espaço já esteja ocupado, pergunta se o jogador quer remover
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
				}	
			}
		}
		
		else {
			printf("\n------------COORDENADAS INVALIDAS!------------");
		}
		
		Sleep(500);
		limparTela();
	} while (1);
}

void jogar() {
	do {
		printf("---------------------------------------------");
		printf("\nDigite a dimensao desejada (de 10 a 60): ");
		scanf("%d", &dimensao);
		fclear();
		printf("---------------------------------------------");
		Sleep(500);
		
		//Validação do tamanho do tabuleiro
		if ((dimensao < 10) || (dimensao > 60)) {
			printf("\n------------DIMENSAO INVALIDA!------------");
			Sleep(500);
			limparTela();
		}
		
		else {
			//Inicializa as matrizes com células vazias
			for (int linha = 0; linha < dimensao; linha++) {
				for (int coluna = 0; coluna < dimensao; coluna++) {
					matriz [linha] [coluna] = '.';
					matrizAuxiliar [linha] [coluna] = '.';
				}
			}
			
			break;
		}
	} while (1);
	
	//Loop principal do jogo
	do {
		//Exibe o menu inicial
		menu();
	
		switch (op) {
			case('1'): 
				limparMapa();
				break;
				
			case('2'): 
				limparTela();
				//apresentarMapa();
				incluirExcluir();
				break;
			
			case('3'): 
				char simNao; //Variável para armazenar a resposta do usuário (S ou N)
				
				do {
					limparTela();
					apresentarMapa();
					printf("\n-----------------------------------------------------------------------------------------");
					printf("\nDeseja que sejam apresentadas as celulas vizinhas-mortas? (S/N) (Digite 0 para sair): ");
					scanf(" %c", &simNao);
					fclear();
					simNao = toupper(simNao);
					printf("-----------------------------------------------------------------------------------------");
					
					//Verifica a resposta do usuário
					if (simNao == 'S') {
						mostrar = 1;
					}
					
					else if (simNao == 'N') {
						mostrar = 0;
					}
					
					else if (simNao == '0') {
						break;
					}
					
					else {
						printf("\n\n--------------OPCAO INVALIDA--------------");
					}
					
					Sleep(500);
				} while (1);
								
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

void limparGeracao() {
	
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
	apresentarMapa();
	printf("\n---------------MAPA LIMPO!---------------\n");
	Sleep(1000);
}

void limparMatriz() {
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matriz [i] [j] = '.';
		}
	}
}

void limparMatrizAux() {
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matrizAuxiliar [i] [j] = '.';
		}
	}
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
	int flag = 0;
	
	do {
		limparTela();
		
		printf("-------------------------------------");
		printf("\nAvancar manual ou automaticamente? ");
		printf("\n0 - Manual | 1 - Automatico: ");
		scanf("%d", &flag);
		printf("-------------------------------------");
		
		if (flag != 0 && flag !=1) {
			printf("\n\n--------------OPCAO INVALIDA--------------");
		}
		
		else {
			break;
		}
		
		Sleep(500);
		fclear();
	} while(1);
		
	if (flag == 0) {
		int opcaoManual = -1;
		printf("\n");
		apresentarMapa(); 
		
		do {
			if (existemVivos() == 0) {
				printf("\n------------------------------------------");
				printf("\n0 CELULAS VIVAS - FIM DA SIMULACAO MANUAL");
				printf("\n------------------------------------------\n\n");
				system("pause");
				break;
			}
			
			printf("\n--------------GERACAO MANUAL--------------");
			printf("\n| 1 - Proxima Geracao                    |");
			printf("\n| 0 - Sair do modo manual                |");
			printf("\n------------------------------------------");
			printf("\nOpcao selecionada: ");
			scanf("%d", &opcaoManual);
			fclear();

			if (opcaoManual == 1) {
				limparTela();
				proximaGeracao();
			}
			
			else if (opcaoManual == 0) {
				break;
			}
			
			else {
				printf("\n--------------OPCAO INVALIDA--------------");
				Sleep(500);
				limparTela();
				apresentarMapa();
			}
		} while (1);
	}
	
	if (flag == 1) {
		int loop;
		int velocidade;
		
		limparTela();
		printf("-----------------------------------------------------------");
		printf("\nQuantas geracoes?: ");
		scanf("%d", &loop);
		fclear();
		
		printf("\nDefina a velocidade de sucessao (em segundos):");
		printf("\n0 - Passo-a-passo (aperte ENTER para avancar)");
		printf("\n1 a 10 - Velocidade automatica (segundos entre geracoes)");
		printf("\nVelocidade: ");
		scanf("%d", &velocidade);
		fclear();
		printf("-----------------------------------------------------------");
		
		if (velocidade < 0 || velocidade > 10) {
			printf("\n\n--------------OPCAO INVALIDA--------------");
			printf("\n\nUsando velocidade padrao: 1 segundo.");
			velocidade = 1;
			Sleep(1000);
		}
		
		limparTela();
		apresentarMapa();
		
		if (velocidade == 0) {
			while (loop > 0) {
				limparTela();
				
				if (existemVivos() == 0) {
					printf("\n----------------------------------------------");
					printf("\n0 CELULAS VIVAS - FIM DA SIMULACAO AUTOMATICA");
					printf("\n----------------------------------------------\n\n");
					break;
				}
				
				printf("\nPressione ENTER para a proxima geracao\n");
				getchar();
				
				proximaGeracao();
				loop--;
			}
			
			system("pause");
		}
		
		else {
			while (loop > 0) {
				if (existemVivos() == 0) {
					printf("\n----------------------------------------------");
					printf("\n0 CELULAS VIVAS - FIM DA SIMULACAO AUTOMATICA");
					printf("\n----------------------------------------------\n\n");
					break;
				}
				
				tempo(velocidade);
				proximaGeracao();
				loop--;
			}
			system("pause");
		}
	}
}

void proximaGeracao() {
	limparMatrizAux();
	gerarVivas();
	
	for (int i = 0; i < dimensao; i++) {
		for (int j = 0; j < dimensao; j++) {
			matriz[i][j] = matrizAuxiliar[i][j];
		}
	}
	
	geracao++;
	apresentarMapa();
}

void recuperarGeracao() {
	
}
