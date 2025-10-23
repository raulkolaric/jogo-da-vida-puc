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
	if (linha - 1 >= 0 && coluna - 1 >= 0){
		if (matriz[linha - 1][coluna - 1] == 'O'){
			qtd++;
		}
	}
	
	if (linha - 1 >= 0 && coluna >= 0){
		if (matriz[linha - 1][coluna] == 'O'){
			qtd++;
		}
	}
	
	if (linha - 1 >= 0 && coluna + 1 < dimensao){
		if (matriz[linha - 1][coluna + 1] == 'O'){
			qtd++;
		}
	}
		
	//2 laterais
	if (linha >= 0 && coluna - 1 >= 0){
		if (matriz[linha][coluna - 1] == 'O'){
			qtd++;
		}
	}
	
	if (linha >= 0 && coluna + 1 < dimensao){
		if (matriz[linha][coluna + 1] == 'O'){
			qtd++;
		}
	}
		
	//3 inferiores
	if (linha + 1 < dimensao && coluna - 1 >= 0){
		if (matriz[linha - 1][coluna - 1] == 'O'){
			qtd++;
		}
	}
	
	if (linha + 1 < dimensao && coluna >= 0){
		if (matriz[linha - 1][coluna] == 'O'){
			qtd++;
		}
	}
	
	if (linha + 1 < dimensao && coluna + 1 < dimensao){
		if (matriz[linha - 1][coluna + 1] == 'O'){
			qtd++;
		}
	}
	
	return qtd;
}


void gravarGeracao() {
	
}

void gerarMortas() {
	
	for (int i = 0; i < dimensao; i++) {
		for (int j = 0; j < dimensao; j++) {
			int qtd = calcularVizinhos(i, j);
			
			if (qtd <= 1) {
				matrizAuxiliar[i][j] = '.';
			}
			if (qtd >= 4) {
				matrizAuxiliar[i][j] = '.';
			}
		}
	}
}

void gerarVivas() {
	
	for (int i = 0; i < dimensao; i++) {
		for (int j = 0; j < dimensao; j++) {
			int qtd = calcularVizinhos(i, j);
			
			if (qtd == 3) {
				matrizAuxiliar[i][j] = 'O';
			}
		}
	}
}	


void incluirExcluir() {
	do {
		apresentarMapa();
		//limparTela();
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
				
				//apresentarMapa();
				Sleep(300);
    			limparTela();
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
				limparTela();
				//apresentarMapa();
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

void limparMatrizAux() {
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matrizAuxiliar[i][j] = '.';
		}
	}
}

void limparMatriz() {
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matriz[i][j] = '.';
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
	//flag
	int flag = 0;
	printf("Avancar manual ou automaticamente?\n[0] Manual\n[1] Automatico\n");
	do {
		scanf("%d", &flag);
		if(flag != 0 || flag !=1) {
			printf("Opção invalida.");
		}
	} while(flag != 0 || flag !=1);
		
	//manual 0
	if (flag == 0) {
		
	}
	//automatico 1
	if (flag == 1){
		int loop;
		printf("Quantas geracoes?\n");
		scanf("%d", &loop);
		
		while(loop>0){
			proximaGeracao();
			loop = loop - 1;
		}

	}
}

void proximaGeracao() {
	limparMatrizAux();
	gerarMortas();
	gerarVivas();
	limparMatriz();	
	//copia matriz auxiliar na matriz atual
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matriz[i][j] = matrizAuxiliar[i][j];
		}
	}
	apresentarMapa();
}

void recuperarGeracao() {
	
}




















