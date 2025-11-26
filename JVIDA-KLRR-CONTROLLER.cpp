//JVIDA-6-KLRR-CONTROLLER.cpp - Projeto Jogo da Vida
//25/11/2025 - Grupo: KLRR
//Kaua Bezerra Brito
//Liam Vedovato Lopes
//Raul Kolaric
//Rodrigo Ward Leite

#include "JVIDA-KLRR-CONTROLLER.h"
#include "JVIDA-KLRR-VIEW.cpp"

//Exibe as listas de celulas (vivas, mortas e proximas vivas)
void apresentarListas() {
	printf("\n--------------Listas de Celulas--------------\n\n");
	
	mostrarLvivo();
	mostrarLmorto();
	mostrarLvivoprox();
	
	printf("\n---------------------------------------------\n\n");
}

//Atualiza a matriz a partir da lista de vivos da proxima geracao
void atualizaMatrizDaLista() {
	limparMatriz();
	
	TipoCel *aux = pvivoprox;
	
	while (aux != NULL) {
		matriz[aux->lin][aux->col] = 'O';
		aux = aux->next;
	}
}

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

//Inclui uma celula na lista de mortos-vizinhos
void carregarMorto(int linha, int coluna) {
	TipoCel *aux = (TipoCel *) malloc(sizeof(TipoCel));
	
	if (aux == NULL) {
		printf("Sem espaco na memoria para inclusao de celula morta-vizinha\n");
		return;
	}
	
	aux->lin = linha;
	aux->col = coluna;
	
	if (totmorto == 0) {
		pmorto = aux;
		pmorto->next = NULL;
	}
	else {
		aux->next = pmorto;
		pmorto = aux;
	}
	
	totmorto++;
}

//Inclui uma celula na lista de vivos
void carregarVivo(int linha, int coluna) {
    TipoCel *aux = pvivo;
    while (aux != NULL) {
        if (aux->lin == linha && aux->col == coluna) return;
        aux = aux->next;
    }

    //Remove da lista de mortos se estiver la
    TipoCel *m = pmorto;
    TipoCel *prevm = NULL;
    while (m != NULL) {
        if (m->lin == linha && m->col == coluna) {
            if (prevm == NULL) pmorto = m->next;
            else prevm->next = m->next;
            free(m);
            totmorto--;
            break;
        }
        prevm = m;
        m = m->next;
    }

    //Insere em pvivo 
    TipoCel *novo = (TipoCel *) malloc(sizeof(TipoCel));
    if (!novo) { printf("Sem memoria (carregarVivo)\n"); return; }
    novo->lin = linha;
    novo->col = coluna;
    novo->next = pvivo;
    pvivo = novo;
    totvivo++;
    matriz[linha][coluna] = 'O'; // atualiza matriz imediatamente
}

//Inclui uma celula na lista de vivos da proxima geracao
void carregarVivoprox(int linha, int coluna) {
	TipoCel *aux = (TipoCel *) malloc(sizeof(TipoCel));
	
	if (aux == NULL) {
		printf("Sem espaco na memoria para inclusao de celula viva proxima geracao\n");
		return;
	}
	
	aux->lin = linha;
	aux->col = coluna;
	
	if (totvivoprox == 0) {
		pvivoprox = aux;
		pvivoprox->next = NULL;
	}
	
	else {
		aux->next = pvivoprox;
		pvivoprox = aux;
	}
	
	totvivoprox++;
}

void excluirLMorto(int linha, int coluna) {
    if (pmorto == NULL) return;

    TipoCel *aux = pmorto;
    TipoCel *prev = NULL;

    while (aux != NULL && (aux->lin != linha || aux->col != coluna)) {
        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL) {
        return;
    }

    if (prev == NULL) {
        pmorto = aux->next;
    } 
	
	else {
        prev->next = aux->next;
    }

    free(aux);
    totmorto--;
}

void excluirLVivo(int linha, int coluna) {
    if (pvivo == NULL) return;

    TipoCel *aux = pvivo;
    TipoCel *prev = NULL;

    while (aux != NULL && (aux->lin != linha || aux->col != coluna)) {
        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL) return;

    if (prev == NULL) pvivo = aux->next;
    else prev->next = aux->next;

    free(aux);
    totvivo--;
}

int existemVivos() {
    if (totvivo > 0) {
    	return 1;
	}
    
    return 0; 
}

void gerarListaMortos() {
    limparLmorto();

    TipoCel *aux = pvivo;

    while (aux != NULL) {
        int lin = aux->lin;
        int col = aux->col;

        // varre os 8 vizinhos da celula viva atual
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nL = lin + i;
                int nC = col + j;

                if ((i != 0 || j != 0) && nL >= 0 && nL < dimensao && nC >= 0 && nC < dimensao) {
                    if (matriz[nL][nC] != 'O') {
                        int vivos = calcularVizinhos(nL, nC);

                        if (vivos > 0 && vivos <= 3) {
                            int jaExiste = 0;
                            TipoCel *busca = pmorto;
                            while (busca != NULL) {
                                if (busca->lin == nL && busca->col == nC) {
                                    jaExiste = 1;
                                    break;
                                }
                                busca = busca->next;
                            }
                            if (jaExiste == 0) {
                                carregarMorto(nL, nC);
                            }
                        }
                    }
                }
            }
        }

        aux = aux->next;
    }
}

//Gera a lista de celulas vivas a partir da matriz atual
void gerarListaVivos() {
	limparLvivo();
	
	for (int i = 0; i < dimensao; i++) {
		for (int j = 0; j < dimensao; j++) {
			if (matriz[i][j] == 'O') {
				carregarVivo(i, j);
			}
		}
	}
}

// Gera a lista de vivos da proxima geracao
void gerarVivas() {
    limparLvivoprox(); // limpa a lista anterior da proxima geracao

    TipoCel *aux = pvivo;

    //Celulas vivas que sobrevivem (2 ou 3 vizinhos vivos)
    while (aux != NULL) {
        int qtd = calcularVizinhos(aux->lin, aux->col);
        if (qtd == 2 || qtd == 3) {
            carregarVivoprox(aux->lin, aux->col);
        }
        aux = aux->next;
    }

    //Celulas mortas que "nascem" (3 vizinhos vivos)
    TipoCel *auxM = pmorto;
    while (auxM != NULL) {
        int qtd = calcularVizinhos(auxM->lin, auxM->col);
        if (qtd == 3) {
            carregarVivoprox(auxM->lin, auxM->col);
        }
        auxM = auxM->next;
    }
}

//Grava no .dat
void gravarGeracao() {
    FILE *arq;
    char nomeArquivo[] = "geracoes.dat";
    TipoCel *aux = pvivo;
    int contador = 0;

    //Conta celulas vivas
    while (aux != NULL) {
        contador++;
        aux = aux->next;
    }

    if (contador == 0) {
    	printf("----------------------------------\n");
        printf("Nenhuma celula viva para gravar.\n");
        printf("----------------------------------\n");
        Sleep(1000);
        return;
    }

    //Abre o arquivo
    arq = fopen(nomeArquivo, "ab");
    if (arq == NULL) {
    	printf("--------------------------------------\n");
        printf("Erro ao abrir o arquivo de gravacao.\n");
        printf("--------------------------------------\n");
        Sleep(1000);
        return;
    }

    //Escreve cabecalho simples: numero da geracao e quantidade
    fwrite(&geracao, sizeof(int), 1, arq);
    fwrite(&contador, sizeof(int), 1, arq);

    //Escreve as coordenadas vivas (lin, col)
    aux = pvivo;
    while (aux != NULL) {
        fwrite(&(aux->lin), sizeof(int), 1, arq);
        fwrite(&(aux->col), sizeof(int), 1, arq);
        aux = aux->next;
    }

    fclose(arq);

	printf("------------------------------------------------------------------------\n");
	printf("Geracao %d gravada com sucesso em '%s' (%d celulas vivas).\n",
           geracao, nomeArquivo, contador);
	printf("------------------------------------------------------------------------\n");
    Sleep(1000);
}

void incluirExcluir() {
	do {
		apresentarMapa();
		printf("-------------------------------------------------------------------");
		printf("\nCoordenadas das Celulas Vivas da Geracao (0 0 para sair): ");
		scanf("%d %d", &coordenadaX, &coordenadaY);
		printf("-------------------------------------------------------------------\n");
		
		if ((coordenadaX == 0) && (coordenadaY == 0)) {
			fclear();
			break;
		}
		
		if (((coordenadaX >= 1) && (coordenadaX <= dimensao)) && ((coordenadaY >= 1) && (coordenadaY <= dimensao))) {
			if (matriz [coordenadaX - 1] [coordenadaY - 1] != 'O') {
				matriz [coordenadaX - 1] [coordenadaY - 1] = 'O';
				carregarVivo(coordenadaX - 1, coordenadaY - 1);
				printf("\n-------------CELULA ADICIONADA-------------");
			}
			
			else if (matriz [coordenadaX - 1] [coordenadaY - 1] == 'O') {
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
						excluirLVivo(coordenadaX - 1, coordenadaY - 1);
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
		
		Sleep(1000);
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
		Sleep(250);
		
		//Validacao do tamanho do tabuleiro
		if ((dimensao < 10) || (dimensao > 60)) {
			printf("\n\n------------DIMENSAO INVALIDA!------------");
			Sleep(500);
			limparTela();
		}
		
		else {
			//Inicializa as matrizes com celulas vazias
			for (int linha = 0; linha < dimensao; linha++) {
				for (int coluna = 0; coluna < dimensao; coluna++) {
					matriz [linha] [coluna] = '.';
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
				limparTela();
				printf("\n---------------MAPA LIMPO!---------------\n");
				apresentarMapa();
				Sleep(1000);
				break;
				
			case('2'): 
				limparTela();
				incluirExcluir();
				break;
			
			case('3'): 
				char simNao; //Variavel para armazenar a resposta do usuario (S ou N)
				
				do {
					limparTela();
					apresentarMapa();
					printf("-----------------------------------------------------------------------------------------");
					printf("\nDeseja que sejam apresentadas as celulas vizinhas-mortas? (S/N) (Digite 0 para sair): ");
					scanf(" %c", &simNao);
					fclear();
					simNao = toupper(simNao);
					printf("-----------------------------------------------------------------------------------------");
					
					//Verifica a resposta do usuario
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
				limparTela();
				apresentarMapa();
				system("pause");
				break;
			
			case('6'): 
				limparTela();
				gravarGeracao();
				break;
				
			case('7'): 
				limparTela();
				recuperarGeracao();
				break;
			
			case('8'): 
				regras();
				break;
				
			case('0'):
				break;
		}
	} while (op != '0');
}

void limparGeracao() {
	
}

//Limpa completamente a lista de mortos-vizinhos
void limparLmorto() {
	TipoCel *aux = pmorto;
	TipoCel *prox;
	
	while (aux != NULL) {
		prox = aux->next;
		free(aux);
		aux = prox;
	}
	
	pmorto = NULL;
	totmorto = 0;
}

//Limpa completamente a lista de vivos
void limparLvivo() {
	TipoCel *aux = pvivo;
	TipoCel *prox;
	
	while (aux != NULL) {
		prox = aux->next;
		free(aux);
		aux = prox;
	}
	
	pvivo = NULL;
	totvivo = 0;
}

//Limpa completamente a lista de vivos da proxima geracao
void limparLvivoprox() {
	TipoCel *aux = pvivoprox;
	TipoCel *prox;
	
	while (aux != NULL) {
		prox = aux->next;
		free(aux);
		aux = prox;
	}
	
	pvivoprox = NULL;
	totvivoprox = 0;
}

void limparMapa() {
	for (int linha = 0; linha < dimensao; linha++) {
		for (int coluna = 0; coluna < dimensao; coluna++) {
			matriz [linha] [coluna] = '.';
		}
	}
	
	limparLvivo();
	limparLmorto();
	limparLvivoprox();
}

void limparMatriz() {
	for (int i = 0; i < dimensao ; i++){
		for (int j = 0; j < dimensao ; j++){
			matriz [i] [j] = '.';
		}
	}
}

void mostrarEsconder() {
	//Se a opcao de mostrar celulas vizinhas-mortas estiver ativada
	if (mostrar == 1) {
		for (int linha = 0; linha < dimensao; linha++) {
			for (int coluna = 0; coluna < dimensao; coluna++) {
				if (matriz [linha] [coluna] != 'O') {
					int vivos = 0;
					
					//Verifica os 8 vizinhos da celula (varre de -1 a +1 em linha e coluna)
					for (int l = -1; l <= 1; l++) {
						for (int c = -1; c <= 1; c++) {
							int nL = linha + l;
							int nC = coluna + c;
							
							//Garante que nao este contando a propria celula e que esta dentro dos limites
							if ((l != 0 || c != 0) && nL >= 0 && nL < dimensao && nC >= 0 && nC < dimensao) {
								if (matriz [nL] [nC] == 'O') {
									vivos++;
								}
							}
						}
					}
					
					//Se houver pelo menos uma celula viva vizinha, marca a celula atual com '+'
					if (vivos > 0) {
						matriz [linha] [coluna] = '+';
					}
				}
			}
		}
	}
	
	//Se a opcao de mostrar estiver desativada, remove os '+' e volta para '.'
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

//Mostra todas as celulas da lista de mortos-vizinhos
void mostrarLmorto() {
	TipoCel *aux = pmorto;
	
	printf("Lista de celulas mortas-vizinhas (%d): ", totmorto);
	
	if (totmorto > 0) {
		while (aux->next != NULL) {
			printf("(%d,%d) ", aux->lin + 1, aux->col + 1);
			aux = aux->next;
		}
		printf("(%d,%d)", aux->lin + 1, aux->col + 1);
	}
	
	printf("\n");
}

//Mostra todas as celulas da lista de vivos
void mostrarLvivo() {
	TipoCel *aux = pvivo;
	
	printf("Lista de celulas vivas (%d): ", totvivo);
	
	if (totvivo > 0) {
		while (aux->next != NULL) {
			printf("(%d,%d) ", aux->lin + 1, aux->col + 1);
			aux = aux->next;
		}
		printf("(%d,%d)", aux->lin + 1, aux->col + 1);
	}
	
	printf("\n");
}

//Mostra todas as celulas da lista de vivos da proxima geracao
void mostrarLvivoprox() {
	TipoCel *aux = pvivoprox;
	
	printf("Lista de celulas vivas proxima geracao (%d): ", totvivoprox);
	
	if (totvivoprox > 0) {
		while (aux->next != NULL) {
			printf("(%d,%d) ", aux->lin + 1, aux->col + 1);
			aux = aux->next;
		}
		printf("(%d,%d)", aux->lin + 1, aux->col + 1);
	}
	
	printf("\n");
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
				printf("------------------------------------------");
				printf("\n0 CELULAS VIVAS - FIM DA SIMULACAO MANUAL");
				printf("\n------------------------------------------\n\n");
				system("pause");
				return;
			}
			
			printf("--------------GERACAO MANUAL--------------");
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
    gerarListaVivos();
    gerarListaMortos();
    gerarVivas();
    
    atualizaMatrizDaLista(); 
    
    gerarListaVivos();
    gerarListaMortos();
    gerarVivas();
    
    geracao++;
    apresentarMapa();
}

//Recupera a gravacao
void recuperarGeracao() {
    static int indiceLeitura = 0; //Mantem progresso entre chamadas
    FILE *arq;
    char nomeArquivo[] = "geracoes.dat";
    int numGeracao = 0, qtd = 0;

    arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) {
        printf("\nNenhum arquivo de geracao encontrado ('%s').\n", nomeArquivo);
        Sleep(1000);
        return;
    }

    //Descobre quantas geracoes existem no arquivo
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    rewind(arq);

    long posicao = 0;
    int totalGeracoes = 0;
    while (posicao < tamanho) {
        int g, q;
        fread(&g, sizeof(int), 1, arq);
        fread(&q, sizeof(int), 1, arq);
        fseek(arq, q * sizeof(int) * 2, SEEK_CUR);
        totalGeracoes++;
        posicao = ftell(arq);
    }

    if (totalGeracoes == 0) {
        printf("\nArquivo vazio, nenhuma geracao para carregar.\n");
        fclose(arq);
        Sleep(1000);
        return;
    }

    if (indiceLeitura >= totalGeracoes) {
        printf("\nFim das geracoes gravadas. Reiniciando leitura.\n");
        indiceLeitura = 0;
    }

    //Move ate a geracao desejada
    rewind(arq);
    for (int i = 0; i < indiceLeitura; i++) {
        int g, q;
        fread(&g, sizeof(int), 1, arq);
        fread(&q, sizeof(int), 1, arq);
        fseek(arq, q * sizeof(int) * 2, SEEK_CUR);
    }

    //Le a proxima geracao
    fread(&numGeracao, sizeof(int), 1, arq);
    fread(&qtd, sizeof(int), 1, arq);

    //Limpa o tabuleiro antes de carregar
    limparMapa();

    printf("\nCarregando geracao %d (%d celulas vivas)...\n", numGeracao, qtd);

    for (int i = 0; i < qtd; i++) {
        int lin, col;
        fread(&lin, sizeof(int), 1, arq);
        fread(&col, sizeof(int), 1, arq);
        if (lin < dimensao && col < dimensao) {
            matriz[lin][col] = 'O';
            carregarVivo(lin, col);
        }
    }

    geracao = numGeracao;
    indiceLeitura++;
    fclose(arq);

    apresentarMapa();
    Sleep(1000);
}

